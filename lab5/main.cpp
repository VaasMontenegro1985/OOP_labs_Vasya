#include <iostream>
#include "include/list.h"
#include "include/allocator.h"

int main()
{
    StaticStruct<1024> resource; 
 
    std::pmr::polymorphic_allocator<int> allocator(&resource); 
 
    int *pi = allocator.allocate(5); // int *pi = new int[5]; 
 
    for (int i = 0; i < 5; i++) { 
        pi[i] = i * i; 
        std::cout << pi[i] << std::endl; 
    } 
 
    allocator.deallocate(pi, 5);
}
