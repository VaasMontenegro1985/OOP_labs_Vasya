#include <iostream>
#include "point.h" 

class Trapezoid : public Figure
{
    private:
        Point a;
        Point b;
        Point c;
        Point d;
        void check();
        bool isIsosceles();
    public:
        Trapezoid ();
        Trapezoid (Point aPoint, Point bPoint, Point cPoint, Point dPoint);

        Point calcCentrRotation() override;
        operator double() override;
        std::ostream& print (std::ostream& os) const override;
        std::istream& input (std::istream& is) override;

        friend std::ostream& operator<< (std::ostream& os, const Trapezoid &trapezoid);
        friend std::istream& operator>> (std::istream& is, Trapezoid &trapezoid);
};

std::ostream& operator<< (std::ostream& os, const Trapezoid &trapezoid);
std::istream& operator>> (std::istream& is, Trapezoid &trapezoid);