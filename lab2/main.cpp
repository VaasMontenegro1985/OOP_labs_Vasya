#include <iostream>
#include "include/Octal.h"


int main() {
    Octal n1("01234");
    std::initializer_list<unsigned char> digits = {'1', '2', '3'};
    Octal n2(digits);
    std::cout << n1 << std::endl << n2 << std::endl;
}