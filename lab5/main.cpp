#include <iostream>
#include "include/list.h"
#include "include/allocator.h"

struct complex {
    double real;
    double imag;

    complex(double r, double i) : real{r}, imag{i}{}
};

std::ostream& operator<< (std::ostream& os, const complex &complexNumber){
    std::cout << "(" << complexNumber.real << "; " << complexNumber.imag << ")";
    return os;
}


int main()
{

    StaticStruct<1024> resource; 

    ListAllocator<int> allocator(&resource); 

    LinkedList<int> list(allocator);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.push_back(5);
    list.print();
    list.pop_back();
    list.pop_front();
    list.print();

    ListAllocator<complex> allocatorComplex(&resource); 

    LinkedList<complex> listComplex(allocatorComplex);
    listComplex.push_front(complex(1, 2));
    listComplex.push_front(complex(2, 2));
    listComplex.push_front(complex(3, 2));
    listComplex.push_front(complex(4, 2));
    listComplex.push_back(complex(5, 2));
    listComplex.print();
    listComplex.pop_back();
    listComplex.pop_front();
    listComplex.print();


}
