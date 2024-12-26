#pragma once
#include <iostream>
#include <sstream>
#include <mutex>

class Printer : public std::stringstream{
    private:
        static std::mutex mtx;
    public:
        ~Printer();
};