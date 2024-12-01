#pragma once 
#include <set> 
#include <iostream> 
#include <string> 
#include <memory> 
#include "point.h" 
 
enum NPCType { 
    Unknown = 0, 
    VaasMontenegro, 
    JasonBrody, 
    BuckHughes
}; 
 
class NPC; 
class Vaas; 
class Jason; 
class Buck;


 
class NPC { 
    private: 
        static std::set<std::string> usedNames; 
 
        std::string name; 
        NPCType type; 
        Point<int> position; 
 
    public: 
        NPC (NPCType type, std::string name, Point<int> coords); 

        virtual ~NPC (); 

        std::string getName ();
        Point<int> getPos ();
        NPCType getType ();
 
        bool isClose (const std::shared_ptr<NPC> &other, double distance) const; 
 
        virtual bool fight (const Vaas &other) = 0; 
        virtual bool fight (const Jason &other) = 0; 
        virtual bool fight (const Buck &other) = 0; 
 
        virtual bool accept (std::shared_ptr<NPC> other) = 0; 
 
        virtual std::ostream& print (std::ostream &os) = 0; 
 
        friend std::ostream& operator<<(std::ostream &os, NPC &npc);  
};