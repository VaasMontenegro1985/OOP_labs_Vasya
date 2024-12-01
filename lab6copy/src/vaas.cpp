#include "../include/vaas.h"

Vaas::Vaas (Point<int> coords, std::string name) : NPC(NPCType::VaasMontenegro, name, coords) {}

bool Vaas::fight(const Vaas &other) {
   return true;
}

bool Vaas::fight(const Jason &other) {
   return true;
}

bool Vaas::fight(const Buck &other) {
   return false;
}

bool Vaas::accept (std::shared_ptr<NPC> other) {
   return other->fight(*this);
}

std::ostream& Vaas::print (std::ostream &os) {
   os << "Vaas ";
   os << getName();
   os << " on position: ";
   os << getPos();
   os << std::endl;

   return os;
}

std::ostream& operator<<(std::ostream &os, Vaas &vaas) {
   return vaas.print(os);
}