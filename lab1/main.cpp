#include <iostream>
#include "include/check.h"


int main(){
    std::string brackets;
    std::cout << "Input your string:" << std::endl;
    getline(std::cin, brackets);
    bool answer = Check(brackets);
    if (answer) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}