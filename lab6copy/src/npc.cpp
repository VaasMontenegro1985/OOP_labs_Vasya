#include "../include/npc.h"
#include <stdexcept>

NPC::NPC(NPCType t, std::string nameNPC, Point<int> coords){
    if (usedNames.find(name) != usedNames.end()){
        throw new std::logic_error("One of NPC with name '" + name + "' already exist.");
    }
    type = t;
    name = nameNPC;
    position = coords;
};

NPC::~NPC() {
    if (name != "") usedNames.erase(name);
}
// NPC::NPC(NpcType t, std::istream &is);

// void subscribe(std::shared_ptr<IFightObserver>observer );
// void fight_notify(const std::shared_ptr<NPC> defender,bool win);
std::string NPC::getName (){
    return name;
};
Point<int> NPC::getPos (){
    return position;
};
NPCType NPC::getType (){
    return type;
};

bool NPC::isClose(const std::shared_ptr<NPC> &other, double distance) const {  
    if (((other->position - position).abs()) <= distance)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc){
    return npc.print(os);
};



/*

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
   observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(shared_from_this(), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}
*/