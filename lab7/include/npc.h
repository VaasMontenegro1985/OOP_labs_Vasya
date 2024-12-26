#pragma once 
#include <set> 
#include <iostream> 
#include <mutex> 
#include <string> 
#include <memory> 
#include "point.h" 
#include <shared_mutex>
#include <cstdlib>
#include "Observer.h"

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

struct Murder
{
    std::string Murderer;
    std::string Victim;

    Murder(std::string nameMurderer, std::string nameVictim){
        Murderer = nameMurderer;
        Victim = nameVictim;
    };
};

 
class NPC : public Observable<Murder>{
    private: 
        static std::set<std::string> usedNames; 
 
        std::string name; 
        NPCType type;
        std::size_t killDistance;
        std::size_t moveDistance = 0;
        char sprite; 
        bool alive;

    protected:
    mutable std::shared_mutex mtx;
    Point<int> coordinates;
    void fightNotify(std::string nameVictim);

    public: 
        NPC (NPCType type, std::string name, Point<int> coords, std::size_t move, std::size_t kill, char npcSprite); 
        virtual void move(std::size_t mapWidth, std::size_t mapHeight);     

        virtual ~NPC (); 
        std::string getName() const;
        Point<int> getCoords();
        NPCType getType();
        char getSprite();
        std::size_t getMoveDistance();
        std::size_t  getKillDistance();
 
        bool isClose(const std::shared_ptr<NPC> &other) const; 
 
        virtual bool fight(const Vaas &other) = 0; 
        virtual bool fight(const Jason &other) = 0; 
        virtual bool fight(const Buck &other) = 0; 
 
        virtual bool accept(std::shared_ptr<NPC> other) = 0; 
        virtual std::ostream& print(std::ostream &os) = 0;

        
        bool isAlive();
        void kill();

        friend std::ostream& operator<<(std::ostream &os, NPC &npc);  
};