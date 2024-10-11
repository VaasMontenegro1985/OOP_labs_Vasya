#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "../include/rhombus.h"
#include "../include/point.h"
#define EPS = 0.0000001

Rhombus::void check(Point aPoint, Point bPoint, Point cPoint){
    Point ab = bPoint - aPoint;
    Point bc = bPoint - cPoint;
    if (fabs(ab.abs() - bc.abs()) > EPS){
        throw std::invalid_argument("Invalid coordinates, it can't be a Rhombus");}
};

Rhombus::Rhombus() : a{Point()}, b{Point(1.0, 0.0)}, c{Point(0.0, 1.0)}, d{Point(1.0)} {};

Rhombus::Rhombus(Point aPoint, Point bPoint, Point cPoint) : a{aPoint}, b{bPoint}, c{cPoint}, d{aPoint + cPoint - bPoint}
{
    check(aPoint, bPoint, cPoint);
}
std::istream &Rhombus::input(std::istream &is) {
    
    
    std::cout <<"Input a: "; 
    is >> a; 
    std::cout << "\tInput b: "; 
    is >> b;
    std::cout << "\tInput c: "; 
    is >> c; 
    std::cout << std::endl; 

    d = a + c - b;

    check(a, b, c);

    return is; 
};

std::ostream& print (std::ostream& os) {
    os << "Rhombus have coordinates:" << std::endl;
    os << a;
    os << b;
    os << c;
    os << d;
    return os;
}

Rhombus::Point calcCentrRotation(){
    Point CentrRotation = (a + b + c + d) * (1/4);
    return CentrRotation;
};

Rhombus::operator double(){
    Point ac = a - c;
    Point bd = b - d;
    double diagonal1 = ac.abs();
    double diagonal2 = bd.abs();
    return(diagonal1*diagonal2/2.0);
};

std::ostream& operator<< (std::ostream& os, const Rhombus &rhombus){
    return rhombus.print(os);
};


std::istream& operator>> (std::istream& is, Rhombus &rhombus){ 
    return rhombus.input(is);
};
