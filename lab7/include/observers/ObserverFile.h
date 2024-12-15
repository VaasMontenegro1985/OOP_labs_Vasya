#pragma once 
#include <iostream> 
#include <fstream> 
#include "../Observer.h" 
#include "../NPC.h" 
 
class ObserverFile : public IObserver<Murder> { 
    private: 
        std::ofstream file; 
     
    protected: 
        void notify (Murder event) override; 
 
    public: 
        ObserverFile (std::string filename); 
        ~ObserverFile (); 
};