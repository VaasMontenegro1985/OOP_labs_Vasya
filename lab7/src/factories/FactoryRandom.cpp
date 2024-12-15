#include "../../include/factories/FactoryRandom.h"
#include "../../include/factories/FactoryFile.h"
#include <stdexcept>

void FactoryRandom::namesVaasPush(){ 
    std::ifstream inputFile("../unicNames/vaas.txt"); 
 
    std::string oneName; 
 
    while (!inputFile.eof()) { 
        std::getline(inputFile, oneName); 
        namesVaas.push_back(oneName); 
    } 
    inputFile.close(); 
} 
 
void FactoryRandom::namesJasonPush(){ 
    std::ifstream inputFile("../unicNames/jason.txt"); 
 
    std::string oneName; 
 
    while (!inputFile.eof()) { 
        std::getline(inputFile, oneName); 
        namesJason.push_back(oneName); 
    } 
    inputFile.close(); 
} 
 
void FactoryRandom::namesBuckPush(){ 
    std::ifstream inputFile("../unicNames/buck.txt"); 
 
    std::string oneName; 
 
    while (!inputFile.eof()) { 
        std::getline(inputFile, oneName); 
        namesBuck.push_back(oneName); 
    } 
    inputFile.close(); 
}

Point<int> FactoryRandom::getRandomPosition(){
    int coordX = std::rand() % mapWidth;
    int coordY = std::rand() % mapHeight;
    return Point(coordX, coordY);
}

std::string FactoryRandom::giveName(NPCType type, std::size_t countOfNPCType){
    switch (type)
    {
    case NPCType::VaasMontenegro:
        return namesVaas[countOfNPCType] + " Vaas";
    
    case NPCType::JasonBrody:
        return namesJason[countOfNPCType] + " Jason";
    
    case NPCType::BuckHughes:
        return namesBuck[countOfNPCType] + " Buck";

    default:
        throw std::logic_error("Unknown NPC type");
    }
}

FactoryRandom::FactoryRandom(std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{
    namesVaasPush();
    namesJasonPush();
    namesBuckPush();
    
}

std::shared_ptr<NPC> FactoryRandom::CreateVaas(){
    return std::make_shared<Vaas>(getRandomPosition(), giveName(NPCType::VaasMontenegro, Vaas::getCount()));
}

std::shared_ptr<NPC> FactoryRandom::CreateJason(){
    return std::make_shared<Jason>(getRandomPosition(), giveName(NPCType::JasonBrody, Jason::getCount()));
}

std::shared_ptr<NPC> FactoryRandom::CreateBuck(){
    return std::make_shared<Buck>(getRandomPosition(), giveName(NPCType::BuckHughes, Buck::getCount()));
}

std::shared_ptr<NPC> FactoryRandom::CreateNPC (NPCType type){
    switch (type)
    {
    case NPCType::VaasMontenegro:
        return CreateVaas();
    
    case NPCType::JasonBrody:
        return CreateJason();
    
    case NPCType::BuckHughes:
        return CreateBuck();

    default:
        throw std::logic_error("Unknown NPC type");
    
}
}
std::shared_ptr<NPC> FactoryRandom::CreateRandomNPC(){
    return CreateNPC(NPCType(std::rand() % 3 + 1));
}