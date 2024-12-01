#include "../include/jason.h"

Jason::Jason(Point<int> coords, std::string name) : NPC(NPCType::JasonBrody, name, coords) {}

bool Jason::fight (const Jason &other) {
    return false;
}

bool Jason::fight (const Vaas &other) {
    return false;
}

bool Jason::fight (const Buck &other) {
    return true;
}

bool Jason::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

std::ostream& Jason::print (std::ostream &os) {
    os << "Jason";
   os << getName();
   os << " on position: ";
   os << getPos();
   os << std::endl;

    return os;
}

std::ostream& operator<<(std::ostream &os, Jason &jason) {
    return jason.print(os);
}