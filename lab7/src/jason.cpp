#include "../include/jason.h"

std::size_t Jason::count = 0;

Jason::Jason(Point<int> coords, std::string name) : NPC(NPCType::JasonBrody, name, coords, 5, 10, 'J') {   
    count++;
}

size_t Jason::getCount(){
   return count;
};

bool Jason::fight (const Jason &other) {
    return false;
}

bool Jason::fight (const Vaas &other) {
    return false;
}

bool Jason::fight (const Buck &other) {
    fightNotify(other.getName());
    return true;
}

bool Jason::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

std::ostream& Jason::print (std::ostream &os) {
   os << getName();
   os << " on position: ";
   os << getCoords();
   os << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream &os, Jason &jason) {
    return jason.print(os);
}