#include "../include/npc.h"
#include "../include/Observer.h"
#include <stdexcept>
#include <cstdlib>

std::set<std::string> NPC::usedNames;

NPC::NPC(NPCType t, std::string nameNPC, Point<int> coords, std::size_t move, std::size_t kill, char npcSprite){
    if (usedNames.find(name) != usedNames.end()){
        throw new std::logic_error("One of NPC with name '" + name + "' already exist.");
    }
    type = t;
    name = nameNPC;

    moveDistance = move;
    killDistance = kill;
    sprite = npcSprite;
    alive = true;
    coordinates = coords;
};

NPC::~NPC() {
    if (name != "") usedNames.erase(name);
}
std::string NPC::getName() const{
    return name;
};
Point<int> NPC::getCoords (){
    std::shared_lock<std::shared_mutex> (mtx);
    return coordinates;
};
NPCType NPC::getType (){
    return type;
};
char NPC::getSprite(){
    return sprite;
};
std::size_t NPC::getMoveDistance(){
    return moveDistance;
};
std::size_t  NPC::getKillDistance(){
    return killDistance;
};

void NPC::move(std::size_t mapHeight, std::size_t mapWidth){
   std::lock_guard<std::shared_mutex> lock(mtx);

   for (std::size_t i = 0; i < getMoveDistance(); i++){
      Point<int> dCoords(std::rand() % 3 - 1, std::rand() % 3 - 1);

      coordinates = coordinates + dCoords;

      if (coordinates.getX() < 0) coordinates.setX(0);
      if (coordinates.getX() >= mapWidth) coordinates.setX(mapWidth - 1);
      if (coordinates.getY() < 0) coordinates.setY(0);
      if (coordinates.getY() >= mapHeight) coordinates.setY(mapHeight - 1);
   }
};

bool NPC::isAlive(){
    std::shared_lock<std::shared_mutex> lock(mtx);
    return alive;
};
void NPC::kill(){
    std::lock_guard<std::shared_mutex> lock(mtx);
    alive = false;
};

void NPC::fightNotify(std::string victimName){
    notifySubs(Murder(getName(), victimName));
};
bool NPC::isClose(const std::shared_ptr<NPC> &other) const {  
    
    if (((other->coordinates - coordinates).abs()) <= killDistance)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc){
    return npc.print(os);
};


