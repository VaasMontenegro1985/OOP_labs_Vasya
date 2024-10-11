#include <iostream>
#include "point.h" 

class Rhombus : public Figure
{
    private:
        Point a;
        Point b;
        Point c;
        Point d;
        void check(Point aPoint, Point bPoint, Point cPoint);
    public:
        Rhombus ();
        Rhombus (Point aPoint, Point bPoint, Point cPoint);


        Point calcCentrRotation() override;
        operator double() override;
        std::ostream& print (std::ostream& os) const override;
        std::istream& input (std::istream& is) override;

        friend std::ostream& operator<< (std::ostream& os, const Rhombus &rhombus);
        friend std::istream& operator>> (std::istream& is, Rhombus &rhombus);
};

std::ostream& operator<< (std::ostream& os, const Rhombus &rhombus);
std::istream& operator>> (std::istream& is, Rhombus &rhombus);