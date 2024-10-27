#include <iostream>
#include "include/point.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"
#include "include/trapezoid.h"
#include "include/utils.h"

int main()
{
    Point<double> p1(1.0, 2.1);
    Point<double> p2(2.3, 1.0);
    Point p3 = p1 + p2;
    std::cout << p1 << " " << p2 << " " << p3 << std::endl;
    }
