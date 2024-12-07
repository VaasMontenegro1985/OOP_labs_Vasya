#include <iostream> 
#include <memory> 
#include "include/NPC.h" 
#include "include/vaas.h" 
#include "include/buck.h" 
#include "include/jason.h"
#include "include/game.h" 
#include <chrono> 
#include <cstdlib> 
using namespace std::chrono_literals;
const std::size_t mapWidth(50);
const std::size_t mapHeight(10);
const std::size_t quantityNpc(50);
int main () { 
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count(); 
    std::srand(seed); 
     
    Game game(mapWidth, mapHeight); 
 
    std::cout << "Initialization..." << std::endl; 
    
    std::this_thread::sleep_for(1s);
    game.init(quantityNpc); 
    
 
    std::cout << "Saving..." << std::endl; 
    game.saveState("file.txt");
    
    std::this_thread::sleep_for(1s);

    std::cout << "Loading..." << std::endl; 
    game.loadState("file.txt"); 
 
    std::cout << "Initial state: " << std::endl; 
    std::cout << game << std::endl; 

    std::this_thread::sleep_for(1s);
 
    std::cout << std::endl << "===== FIGHT =====" << std::endl << std::endl; 
    game.battle(); 
 
    std::cout << std::endl << "===== FIGHT END =====" << std::endl << std::endl; 
    std::cout << "Survivors:" << std::endl; 
    std::cout << game << std::endl; 
 
    return 0; 
}