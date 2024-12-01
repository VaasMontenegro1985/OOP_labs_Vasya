#include <iostream> 
#include <memory> 
#include "include/NPC.h" 
#include "include/vaas.h" 
#include "include/buck.h" 
#include "include/jason.h" 
 
int main () { 
    std::shared_ptr<NPC> jason{new Jason(Point(0, 0), "American")}; 
    std::shared_ptr<NPC> buck{new Buck(Point(20, 10), "Horny")}; 
    std::shared_ptr<NPC> vaas{new Vaas(Point(30, 40), "Drunk")}; 
 
    std::cout << *jason << std::endl; 
    std::cout << jason->accept(jason) << std::endl; 
    std::cout << buck->accept(jason) << std::endl; 
    std::cout << vaas->accept(jason) << std::endl; 
     
    std::cout << *buck << std::endl; 
    std::cout << jason->accept(buck) << std::endl; 
    std::cout << buck->accept(buck) << std::endl; 
    std::cout << vaas->accept(buck) << std::endl; 
 
    std::cout << *vaas << std::endl; 
    std::cout << jason->accept(vaas) << std::endl; 
    std::cout << buck->accept(vaas) << std::endl; 
    std::cout << vaas->accept(vaas) << std::endl; 
 
    return 0; 
}