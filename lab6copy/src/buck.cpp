#include "../include/buck.h" 

Buck::Buck (Point<int> coords, std::string name) : NPC(NPCType::BuckHughes, name, coords){} 

bool Buck::fight (const Buck &other){ 
   return false; 
} 

bool Buck::fight (const Jason &other){ 
   return false;
} 

bool Buck::fight (const Vaas &other){ 
   return false; 
} 

bool Buck::accept (std::shared_ptr<NPC> other){ 
   return other->fight(*this); 
} 

std::ostream& Buck::print (std::ostream &os){ 
   os << "Buck ";
   os << getName();
   os << " on position: ";
   os << getPos();
   os << std::endl;
   return os; 
} 

std::ostream& operator<<(std::ostream &os, Buck &buck){ 
   return buck.print(os); 
}