#include "../include/printer.h"
#include <mutex>
std::mutex Printer::mtx;

Printer::~Printer(){
    std::lock_guard<std::mutex> lock(mtx);

    std::cout << str();
    std::cout.flush();
};