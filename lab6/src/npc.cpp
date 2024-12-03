#include "../include/npc.h"
#include "../include/Observer.h"
#include <stdexcept>

std::set<std::string> NPC::usedNames;

NPC::NPC(NPCType t, std::string nameNPC, Point<int> coords){
    if (usedNames.find(name) != usedNames.end()){
        throw new std::logic_error("One of NPC with name '" + name + "' already exist.");
    }
    type = t;
    name = nameNPC;
    coordinates = coords;
};

NPC::~NPC() {
    if (name != "") usedNames.erase(name);
}
std::string NPC::getName() const{
    return name;
};
Point<int> NPC::getCoords (){
    return coordinates;
};
NPCType NPC::getType (){
    return type;
};

void NPC::fightNotify(std::string victimName, bool win){
    notifySubs(Murder(getName(), victimName, win));
};
bool NPC::isClose(const std::shared_ptr<NPC> &other, double distance) const {  
    if (((other->coordinates - coordinates).abs()) <= distance)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc){
    return npc.print(os);
};


