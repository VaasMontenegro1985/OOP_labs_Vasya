#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "../include/rectangle.h"
#include "../include/point.h" 
#include "rectangle.h"
#define EPS = 0.00001

Rectangle::void check(Point aPoint, Point bPoint, Point cPoint){
    Point ab = bPoint - aPoint;
    Point bc = bPoint - cPoint;
    if (fabs(ab * bc) > EPS){
        throw std::invalid_argument("Invalid coordinates, it can't be a Rectangle");}
};

Rectangle::Rectangle() : a{Point()}, b{Point(1.0, 0.0)}, c{Point(0.0, 1.0)}, d{Point(1.0)} {};

Rectangle::Rectangle(Point aPoint, Point bPoint, Point cPoint) : a{aPoint}, b{bPoint}, c{cPoint}, d{aPoint + cPoint - bPoint}
{
    check(aPoint, bPoint, cPoint);
}
std::istream &Rectangle::input(std::istream &is) {
    

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

std::ostream& print (std::ostream& os) const{
    os << "Rectangle have coordinates:" << std::endl;
    os << a;
    os << b;
    os << c;
    os << d;
    return os;
}

Rectangle::Point calcCentrRotation(){
    Point CentrRotation = (a + b + c + d) * (1/4);
    return CentrRotation;
};

Rectangle::operator double(){
    Point ab = b - a;
    Point bc = b - c;
    double width = ab.abs();
    double lenght = bc.abs();
    return(width*lenght);
};

std::ostream& operator<< (std::ostream& os, const Rectangle &rectangle){
    return rectangle.print(os);
};


std::istream& operator>> (std::istream& is, Rectangle &rectangle){ 
    return rectangle.input(is);
};
