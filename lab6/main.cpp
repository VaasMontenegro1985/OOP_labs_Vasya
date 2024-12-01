#include <iostream> 
#include <memory> 
#include "include/NPC.h" 
#include "include/vaas.h" 
#include "include/buck.h" 
#include "include/jason.h"
#include "include/game.h" 
#include <chrono> 
#include <cstdlib> 
 
int main () { 
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    std::srand(seed); 
     
    Game game(500, 500); 
 
    std::cout << "Initialization..." << std::endl; 
    game.init(150); 
 
    std::cout << "Saving..." << std::endl; 
    game.saveState("file.txt"); 
 
    std::cout << "Loading..." << std::endl; 
    game.loadState("file.txt"); 
 
    std::cout << "Initial state: " << std::endl; 
    std::cout << game << std::endl; 
 
    std::cout << std::endl << "===== FIGHT =====" << std::endl << std::endl; 
    game.battle(10.0, 500.0, 20.0); 
 
    std::cout << std::endl << "===== FIGHT END =====" << std::endl << std::endl; 
    std::cout << "Survivors:" << std::endl; 
    std::cout << game << std::endl; 
 
    return 0; 
}