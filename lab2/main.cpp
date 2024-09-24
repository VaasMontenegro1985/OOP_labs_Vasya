#include <iostream>
#include "include/Octal.h"


int main() {
    size_t lengthNumber;
    std::cout << "Введите длину первого числа: ";
    std::cin >> lengthNumber;

    unsigned char defaultValue;
    std::cout << "Введите значение по умолчанию для первого числа (0-7): ";
    std::cin >> defaultValue;
    
    Octal number1(lengthNumber, defaultValue);
    std::cout << "Число 1: " << number1 << std::endl;

    std::string stringNumber1;
    std::cout << "Введите строку из цифр для второго числа (от 0 до 7): ";
    std::cin >> stringNumber1;
    Octal number2(stringNumber1);
    std::cout << "Число 2: " << number2 << std::endl;

    std::string stringNumber2;
    std::cout << "Введите строку из цифр для третьего числа (от 0 до 7): ";
    std::cin >> stringNumber2;

    Octal number3(stringNumber2);
    
    std::cout << "Число 3: " << number3 << std::endl;
    Octal sumResult = number1;
    sumResult += number2;
    std::cout << "Сумма Число 1 + Число 2: " << sumResult << std::endl;

    Octal subResult = number1;
    subResult -= number2;
    std::cout << "Разность Число 1 - Число 2: " << subResult << std::endl;
    Octal copyOfNumber1 = number1;
    std::cout << "Копия Числа 1: " << copyOfNumber1 << std::endl;

    Octal movedNumber = std::move(number2);
    std::cout << "Перемещенное Число 2: " << movedNumber << std::endl;

    std::cout << "Сравнение: " << std::endl;
    std::cout << "Число 1 == Копия Числа 1: " << (number1 == copyOfNumber1) << std::endl;
    std::cout << "Число 1 < Число 3: " << (number1 < number3) << std::endl;
    std::cout << "Число 3 > Число 1: " << (number3 > number1) << std::endl;

    return 0;
}
   