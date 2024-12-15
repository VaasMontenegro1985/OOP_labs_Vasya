#include "../../include/factories/FactoryFile.h"
#include <stdexcept>

FactoryFile::FactoryFile (std::string filename) { 
    file.open(filename); 
    if (!file.is_open()) throw std::ios_base::failure("Failed to open file."); 
 
    file >> inFileCount; 
    readCount = 0; 
} 
 
FactoryFile::~FactoryFile () {
    if (file.is_open()) file.close();
}

bool FactoryFile::endOfFile(){
    return readCount >= inFileCount;
}

std::shared_ptr<NPC> FactoryFile::createNPCFromFile(){
    if (endOfFile()) throw std::logic_error("End of file reached.");

    int typeNumeric, coordX, coordY;
    std::string name;

    file >> typeNumeric;
    file >> coordX;
    file >> coordY;
    NPCType type = NPCType(typeNumeric);
    Point<int> coordinates(coordX, coordY);
    file.get(); 
    std::getline(file, name); 
    readCount++; 
 
    switch (type) { 
        case NPCType::VaasMontenegro: 
            return std::make_shared<Vaas>(coordinates, name); 
 
        case NPCType::JasonBrody: 
            return std::make_shared<Jason>(coordinates, name); 
 
        case NPCType::BuckHughes: 
            return std::make_shared<Buck>(coordinates, name); 
         
        default: 
            throw std::logic_error("Unknown NPC type."); 
    } 
} 
FactoryFile::NPCSaver::NPCSaver (std::string filename, std::size_t writeCount) { 
    file.open(filename); 
    if (!file.is_open()) throw std::ios_base::failure("Failed to open file."); 
 
    file << writeCount << std::endl; 
} 
 
FactoryFile::NPCSaver::~NPCSaver () { 
    if (file.is_open()) file.close(); 
} 
 
void FactoryFile::NPCSaver::saveNPC (const std::shared_ptr<NPC> &npc) { 
    file << static_cast<int>(npc->getType()) << std::endl; 
 
    Point pos = npc->getCoords(); 
    file << pos.getX() << std::endl; 
    file << pos.getY() << std::endl; 
 
    file << npc->getName() << std::endl; 
}