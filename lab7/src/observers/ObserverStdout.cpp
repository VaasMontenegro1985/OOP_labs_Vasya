#include "../../include/observers/ObserverStdout.h"
#include "../../include/printer.h"
 
void ObserverStdout::notify (Murder event) { 
    Printer() << event.Murderer << " want to kill " << event.Victim << std::endl; 
}