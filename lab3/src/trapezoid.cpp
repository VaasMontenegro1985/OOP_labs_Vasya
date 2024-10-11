#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "../include/trapezoid.h"
#include "../include/point.h"
#define EPS = 0.0000001

Trapezoid::void check(Point aPoint, Point bPoint, Point cPoint)
{
    Point ab = bPoint - aPoint;
    Point bc = bPoint - cPoint;
    Point cd = cPoint - dPoint;
    Point ad = aPoint - dPoint;
    bool isParallel_ab_cd(fabs(ab * cd - (ab.abs() * cd.abs())) < EPS);
    bool isParallel_bc_ad(fabs(bc * ad - (bc.abs() * ad.abs())) < EPS);
    if (isParallel_ab_cd ^ isParallel_bc_ad)
    {
        throw std::invalid_argument("Invalid coordinates, it can't be a Trapezoid");
    }
};

Trapezoid::Trapezoid() : a{Point()}, b{Point(1.0)}, c{Point(2.0, 1.0)}, d{Point(3.0, 0.0)} {};

Trapezoid::Trapezoid(Point aPoint, Point bPoint, Point cPoint) : a{aPoint}, b{bPoint}, c{cPoint}, d{dPoint}
{
    check(aPoint, bPoint, cPoint, dPoint);
};

Trapezoid::bool isIsosceles(){
    Point ab = bPoint - aPoint;
    Point bc = bPoint - cPoint;
    Point cd = bPoint - aPoint;
    Point ab = aPoint - bPoint;
    if (fabs(ab.abs() - bc.abs()) > std::numeric_limits<double>::epsilon()){
        throw std::invalid_argument("Invalid coordinates, centr can't be found");}
};

std::istream &Trapezoid::input(std::istream &is)
{

    std::cout << "Input a: ";
    is >> a;
    std::cout << "\tInput b: ";
    is >> b;
    std::cout << "\tInput c: ";
    is >> c;
    std::cout << "\tInput d: ";
    is >> d;
    std::cout << std::endl;

    return is;
};

std::ostream &print(std::ostream &os)
{
    os << "Trapezoid have coordinates:" << std::endl;
    os << a;
    os << b;
    os << c;
    os << d;
    return os;
};

Trapezoid::Point calcCentrRotation()
{
    Point CentrRotation = (a + b + c + d) * (1 / 4);
    return CentrRotation;
};

Trapezoid::operator double()
{
    Point ac = a - c;
    Point bd = b - d;
    double diagonal1 = ab.abs();
    double diagonal2 = bc.abs();
    return (diagonal1 * diagonal2 / 2.0);
};

std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid)
{
    return trapezoid.print(os);
};

std::istream &operator>>(std::istream &is, Trapezoid &trapezoid)
{
    return trapezoid.input(is);
};
