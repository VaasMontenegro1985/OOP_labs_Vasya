#include <gtest/gtest.h> 
#include <stdexcept> 
#include "../include/Octal.h" 
 
TEST(OctalTest, default_constructor) { 
    Octal number(1, '0'); 
    Octal numberDefault; 
     
    bool result = number == numberDefault;     
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, incorrect_digit_length_constructor) { 
    EXPECT_THROW(Octal number(1, '8'), std::invalid_argument); 
    EXPECT_THROW(Octal number(1, 'a'), std::invalid_argument); 
} 
 
TEST(OctalTest, incorrect_length_length_constructor) { 
    EXPECT_THROW(Octal number(0, '0'), std::invalid_argument); 
} 
 
TEST(OctalTest, leading_zeros_length_constructor) { 
    Octal numberMultiZeros(2, '0'); 
    Octal numberZero; 
 
    bool result = numberMultiZeros == numberZero;     
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, init_list_constructor) { 
    Octal numberRef(3, '1'); 
    Octal number{'1', '1', '1'}; 
 
    bool result = number == numberRef;     
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, incorrect_digit_init_list_constructor) { 
    std::initializer_list<unsigned char> num1List = {'8'}; 
    std::initializer_list<unsigned char> num2List = {'1', '2', '9', '0'}; 
    std::initializer_list<unsigned char> num3List = {'1', '8', '5', '0', '6'}; 
 
    EXPECT_THROW(Octal number{num1List}, std::invalid_argument); 
    EXPECT_THROW(Octal number{num2List}, std::invalid_argument); 
    EXPECT_THROW(Octal number{num3List}, std::invalid_argument); 
} 
 
TEST(OctalTest, leading_zeros_init_list_constructor) { 
    Octal number1{'0', '0', '1', '2', '3', '4', '0'}; 
    Octal number2{'1', '2', '3', '4', '0'}; 
 
    bool result = number1 == number2;     
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, str_constructor) { 
    Octal numberRef{'1', '2', '3'}; 
    Octal number("123"); 
 
    bool result = number == numberRef; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, incorrect_digit_str_constructor) { 
    EXPECT_THROW(Octal number("8"), std::invalid_argument); 
    EXPECT_THROW(Octal number("1290"), std::invalid_argument); 
    EXPECT_THROW(Octal number("12509"), std::invalid_argument); 
} 
 
TEST(OctalTest, leading_zeros_str_constructor) { 
    Octal number1("0012340"); 
    Octal number2("12340"); 
 
    bool result = number1 == number2;     
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, copy_constructor) { 
    Octal number1("12345"); 
    Octal number2{number1}; 
 
    bool result = number1 == number2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, move_constructor) { 
    Octal numberOriginal("12345"); 
    Octal numberOriginalCopy{numberOriginal}; 
    Octal number{std::move(numberOriginal)}; 
 
    bool result = numberOriginalCopy == numberOriginalCopy; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, assigment) { 
    Octal number1; 
    Octal number2("12345"); 
 
    number1 = number2; 
     
    bool result = number1 == number2; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, self_assigment) { 
    Octal number; 
    EXPECT_THROW(number = number, std::logic_error); 
} 


TEST(OctalTest, ComparisonOperators) {
    const Octal number1({'3', '2', '1'});
    const Octal number2({'3', '2', '1'});
    const Octal number3({'1', '2', '3'});

    bool is1Equal2 = (number1 == number2);
    bool is1Equal3 = (number1 == number3);
    bool is1LessThan2 = (number1 < number2);
    bool is1GreaterThan2 = (number1 > number2);
    bool is1LessThanNumber3 = (number1 < number3);
    bool is1GreaterThanNumber3 = (number1 > number3);

    ASSERT_TRUE(is1Equal2 == true);
    ASSERT_TRUE(is1Equal3 == false);
    ASSERT_TRUE(is1LessThan2 == false);
    ASSERT_TRUE(is1GreaterThan2 == false);
    ASSERT_TRUE(is1LessThanNumber3 == false);
    ASSERT_TRUE(is1GreaterThanNumber3 == true);
}

TEST(OctalTest, add_zero) { 
    Octal number1("1234"); 
    Octal number1Copy{number1}; 
    Octal numberZero; 
 
    number1 += numberZero; 
 
    int result = number1 == number1Copy; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, add) { 
    Octal number1("1023"); 
    Octal number2("35"); 
    Octal numberRes("1060"); 
 
    number1 += number2; 
 
    int result = number1 == numberRes; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, add_extend) { 
    Octal number1("77777"); 
    Octal number2("1"); 
    Octal numberRes("100000"); 
 
    number1 += number2; 
 
    int result = number1 == numberRes; 
    ASSERT_TRUE(result == true); 
}

TEST(OctalTest, sub_zero) { 
    Octal number1("1234"); 
    Octal number1Copy{number1}; 
    Octal numberZero; 
 
    number1 -= numberZero; 
 
    int result = number1 == number1Copy; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, sub) { 
    Octal number1("1060"); 
    Octal number2("35"); 
    Octal numberRes("1023"); 
 
    number1 -= number2; 
 
    int result = number1 == numberRes; 
    ASSERT_TRUE(result == true); 
} 
 
TEST(OctalTest, sub_extend) { 
    Octal number1("100000"); 
    Octal number2("77777"); 
    Octal numberRes("1"); 
 
    number1 -= number2; 
 
    int result = number1 == numberRes; 
    ASSERT_TRUE(result == true); 
}

TEST(OctalTest, substruction_error) { 
    Octal number1("1234"); 
    Octal number2("2345");
 
    EXPECT_THROW(number1 -= number2, std::logic_error); 
} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}