#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/allocator.h"
#include "../include/list.h"

TEST(allocator, alloc_empty) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
 
    bool result = counter == 1; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, alloc_some) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(2); 
    allocator.construct(itemP, &counter); 
    allocator.construct(itemP + 1, &counter); 
 
    bool result = counter == 2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, alloc_begin) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
     
    itemP->~Item(); 
    allocator.deallocate(itemP, 1); 
 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    bool result = counter == 2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, alloc_end) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    bool result = counter == 3; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, alloc_middle) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
    auto itemP2 = allocator.allocate(1); 
    allocator.construct(itemP2, &counter); 
    auto itemP3 = allocator.allocate(1); 
    allocator.construct(itemP3, &counter); 
 
    itemP2->~Item(); 
    allocator.deallocate(itemP2, 1); 
 
    auto itemP4 = allocator.allocate(1); 
    allocator.construct(itemP4, &counter); 
 
    bool result = counter == 3; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, dealloc) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource; 
    std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(1); 
    allocator.construct(itemP, &counter); 
 
    itemP->~Item(); 
    allocator.deallocate(itemP, 1); 
 
    bool result = counter == 0; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(allocator, dealloc_some) { 
    struct Item { 
        int *counter; 
        Item (int *counterVal) : counter{counterVal} { ++(*counter); } 
        ~Item () { --(*counter); } 
    }; 
    int counter = 0; 
 
    StaticStruct<1024> resource;
std::pmr::polymorphic_allocator<Item> allocator(&resource); 
 
    auto itemP = allocator.allocate(5); 
 
    for (int i = 0; i < 5; i++) { 
        allocator.construct(itemP + i, &counter); 
    } 
 
    for (int i = 0; i < 5; i++) { 
        (itemP + i)->~Item(); 
    } 
 
    allocator.deallocate(itemP, 5); 
 
    bool result = counter == 0; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(list, create_empty) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == true); 
} 
 
TEST(list, push_back_not_empty) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(0); 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == false); 
}
 
TEST(list, pop_back) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(6); 
    list.pop_back();
 
    bool result = list.empty(); 
 
    ASSERT_TRUE(result == true); 
} 
 
TEST(list, iterators) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
 
    list.push_back(0); 
    list.push_back(1); 
    list.push_back(2); 
 
    auto it = list.begin(); 
 
    bool correct = true; 
    correct = correct && *it == 0; 
    it++; 
    correct = correct && *it == 1; 
    it++; 
    correct = correct && *it == 2; 
    it++; 
    correct = correct && it == list.end(); 
 
    bool result = correct == true; 
 
    ASSERT_TRUE(result == true); 
} 
 

TEST(list, equal) { 
    StaticStruct<1024> resource; 
    ListAllocator<int> allocator(&resource); 
    LinkedList<int> list(allocator); 
    LinkedList<int> list2(allocator); 
 
    bool emptyEqual = list == list2; 
 
    list.push_back(0); 
    list.push_back(1); 
    list.push_back(2); 
 
    list2.push_back(0); 
    list2.push_back(1); 
    list2.push_back(2); 
 
    bool sameEqual = list == list2; 
 
    list2.push_back(3); 
 
    bool notSameNotEqual = list != list2; 
 
    bool result = emptyEqual && sameEqual && notSameNotEqual; 
 
    ASSERT_TRUE(result == true); 
} 


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}