#pragma once
#include <initializer_list>
#include <string>
#include <fstream>

unsigned char validateDigit(unsigned char digit);

class Octal
{
private:
    size_t size;
    void removeZeros();
    unsigned char *digits = nullptr;
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
    size_t getSize() const;
    unsigned char* getData() const;

    friend std::ostream& operator<< (std::ostream& os, const Octal &number);
};

std::ostream& operator<< (std::ostream& os, const Octal &number);