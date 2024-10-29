#include <initializer_list>
#include <string>
#include "../include/Octal.h"
#include <stdexcept>

unsigned char validateDigit(unsigned char digit)
{
    if (digit < '0' || digit > '7')
        throw std::invalid_argument("Invalid digit");
    return digit;
}

std::ostream &operator<<(std::ostream &os, const Octal &number)
{
    for (int i = number.size - 1; i >= 0; i--)
        os << number.digits[i];
    return os;
};

void Octal::removeZeros()
{
    int firstDigit = 0;

    for (int i = 0; i < size; i++)
    {
        if (digits[i] != '0')
            firstDigit = i;
    }

    unsigned char *newDigits = new unsigned char[firstDigit + 1];

    for (int i = 0; i < firstDigit + 1; i++)
    {
        newDigits[i] = digits[i];
    }

    delete[] digits;

    size = firstDigit + 1;
    digits = newDigits;
}

Octal::Octal() : size{1}, digits{new unsigned char[1]}
{
    digits[0] = '0';
}

Octal::Octal(const size_t &lenghtOfNumber, unsigned char defaultValue)
{
    if (lenghtOfNumber <= 0)
        throw std::invalid_argument("Invalid size");
    validateDigit(defaultValue);
    size = lenghtOfNumber;
    digits = new unsigned char[lenghtOfNumber];

    for (int i = 0; i < lenghtOfNumber; ++i)
    {
        digits[i] = defaultValue;
    }
    removeZeros();
}

Octal::Octal(const std::initializer_list<unsigned char> &values)
{
    size = values.size();
    digits = new unsigned char[size];
    int i = size - 1;
    for (const unsigned char &digit : values)
    {
        digits[i--] = validateDigit(digit);
    }
    removeZeros();
}

Octal::Octal(const std::string &defaultValues)
{
    size = defaultValues.size();
    digits = new unsigned char[size];
    for (int i = 0; i < size; ++i)
    {
        digits[size - 1 - i] = validateDigit(defaultValues[i]);
    }
    removeZeros();
}

Octal::Octal(const Octal &other)
{
    delete[] digits;
    size = other.size;
    digits = new unsigned char[size];
    for (int i = 0; i < size; ++i)
    {
        digits[i] = other.digits[i];
    }
}

Octal::Octal(Octal &&other) noexcept
{
    size = other.size;
    other.size = 0;
    digits = other.digits;
    other.digits = nullptr;
}

Octal::~Octal() noexcept
{
    delete[] digits;
}

Octal &Octal::operator=(const Octal &other)
{
    if (this == &other)
    {
        throw std::logic_error("Self assignment");
    }
    delete[] digits;
    size = other.size;
    digits = new unsigned char[size];
    for (int i = 0; i < size; ++i)
    {
        digits[i] = other.digits[i];
    }
    return *this;
}

bool Octal::operator==(const Octal &other) const
{
    if (size != other.size)
        return false;
    for (int i = 0; i < size; ++i)
    {
        if (digits[i] != other.digits[i])
            return false;
    }
    return true;
}
bool Octal::operator<(const Octal &other) const
{
    if (size < other.size)
        return true;
    if (size > other.size)
        return false;
    for (int i = size - 1; i >= 0; i--)
    {
        if (digits[i] > other.digits[i])
            return false;
        if (digits[i] < other.digits[i])
            return true;
    }
    return false;
}

bool Octal::operator>(const Octal &other) const
{
    if (size > other.size)
        return true;
    if (size < other.size)
        return false;
    for (int i = size - 1; i >= 0; i--)
    {
        if (digits[i] < other.digits[i])
            return false;
        if (digits[i] > other.digits[i])
            return true;
    }
    return false;
}

Octal &Octal::operator+=(const Octal &other)
{
    int maxSize = size > other.size ? size : other.size;
    unsigned char *newDigits = new unsigned char[maxSize + 1];
    int carry = 0;
    for (int i = 0; i < maxSize; ++i)
    {
        int digit1 = i < size ? digits[i] - '0' : 0;
        int digit2 = i < other.size ? other.digits[i] - '0' : 0;
        int sumElements = digit1 + digit2 + carry;
        carry = sumElements >= 8 ? 1 : 0;
        newDigits[i] = '0' + sumElements % 8;
    }
    if (carry == 1)
    {
        newDigits[maxSize] = '1';
        size = maxSize + 1;
    }
    else
    {
        size = maxSize;
    }
    delete[] digits;
    digits = newDigits;
    return *this;
}

Octal &Octal::operator-=(const Octal &other)
{
    if (*this < other)
    {
        throw std::logic_error("Reduced is less than the subtracted");
    }
    unsigned char *newDigits = new unsigned char[size];
    int carry = 0;
    for (int i = 0; i < size; ++i)
    {
        int digit1 = i < size ? digits[i] - '0' : 0;
        int digit2 = i < other.size ? other.digits[i] - '0' : 0;
        int residualElements = digit1 - digit2 - carry;
        carry = residualElements < 0 ? 1 : 0;
        newDigits[i] = '0' + (residualElements < 0 ? residualElements + 8 : residualElements);
    }
    delete[] digits;
    digits = newDigits;
    removeZeros();
    return *this;
}

size_t Octal::getSize() const {
  return size;
}

unsigned char* Octal::getData() const {
  return digits;
}