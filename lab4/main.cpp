#include <iostream>
#include "include/point.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"
#include "include/rectangle.h"
#include "include/array.h"
#include "include/utils.h"

int main()
{
    Array<Figure<double>*> figures;
    figures.append(new Rhombus<double>(Point(0.0, 0.0), Point(1.0, 0.0), Point(1.0, 1.0)));
    figures.append(new Rectangle<double>(Point(0.0, 0.0), Point(2.0, 0.0), Point(2.0, 1.0)));
    figures.append(new Rectangle<double>(Point(1.0, 0.0), Point(2.0, 0.0), Point(2.0, 1.0)));
    figures.append(new Trapezoid<double>(Point(0.0, 0.0), Point(2.0, 1.0), Point(3.0, 1.0), Point(4.0, 0.0)));
    for (int i = 0; i < figures.getSize(); i++)
    {
        std::cout << "Figure's index: " << i << std::endl;
        std::cout << *figures[i];
        std::cout << "Rotation center: " << figures[i]->calcCentrRotation() << std::endl;
        std::cout << "Area: " << static_cast<double>(*figures[i]) << std::endl;
    }
    std::cout << std::endl;

    Array<Rectangle<int>> recs;
    Array<Figure<double>*> figures;


}
