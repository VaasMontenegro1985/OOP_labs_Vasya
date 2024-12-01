#include "../../include/observers/ObserverStdout.h" 
 
void ObserverStdout::notify (Murder event) { 
    std::cout << event.Murderer; 
    std::cout << " " << (event.ResultMurder ? "win" : "lose"); 
    std::cout << " " << event.Victim << std::endl; 
}