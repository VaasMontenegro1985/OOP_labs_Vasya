#pragma once
#include <initializer_list>
#include <string>
#include <fstream>

unsigned char validateDigit(unsigned char digit);

class Octal
{
private:
    unsigned char *digits = nullptr;
    size_t size;
    void removeZeros();

public:
    Octal();
    Octal(const size_t &lenghtOfNumber, unsigned char defaultValue = 0);
    Octal(const std::initializer_list<unsigned char> &defaultValues);
    Octal(const std::string &defaultValues);
    Octal(const Octal &other);
    Octal(Octal &&other) noexcept;
    virtual ~Octal() noexcept;
    Octal &operator=(const Octal &other);
    Octal &operator+=(const Octal &other);
    Octal &operator-=(const Octal &other);
    bool operator==(const Octal &other) const;
    bool operator<(const Octal &other) const;
    bool operator>(const Octal &other) const;

    friend std::ostream& operator<< (std::ostream& os, const Octal &number);
};

std::ostream& operator<< (std::ostream& os, const Octal &number);