#include <gtest/gtest.h>
#include "../include/check.h"

TEST(test_01, basic_test_set)
{
    std::string s = "";
    bool result = Check(s);
    ASSERT_TRUE(result == true);
}

TEST(test_02, basic_test_set)
{
    std::string s = "()";
    bool result = Check(s);
    ASSERT_TRUE(result == true);
}

TEST(test_03, basic_test_set)
{
    std::string s = "()())";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_04, basic_test_set)
{
    std::string s = "()))((())))";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_05, basic_test_set)
{
    std::string s = "((()()))";
    bool result = Check(s);
    ASSERT_TRUE(result == true);
}

TEST(test_06, basic_test_set)
{
    std::string s = "((()()()))";
    bool result = Check(s);
    ASSERT_TRUE(result == true);
}

TEST(test_07, basic_test_set)
{
    std::string s = "(((()()))";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_08, basic_test_set)
{
    std::string s = "((()((((((((((((((((((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))))))))))))))))))()))";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_09, basic_test_set)
{
    std::string s = "((()((((((((((()))))))))))))))()))";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_10, basic_test_set)
{
    std::string s = ")(()))";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}

TEST(test_11, basic_test_set)
{
    std::string s = "(())((()())())";
    bool result = Check(s);
    ASSERT_TRUE(result == true);
}
TEST(test_12, basic_test_set)
{
    std::string s = "(";
    bool result = Check(s);
    ASSERT_TRUE(result == false);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}