#include "../../include/factories/FactoryRandom.h"
#include "../../include/factories/FactoryFile.h"
#include <stdexcept>

std::vector<std::string> FactoryRandom::namesVaasPush(){
    std::vector<std::string> namesVaasVector;
    std::ifstream inputFile("../../unicNames/vaas.txt");

    std::string oneName;

    while (std::getline(inputFile, oneName)) {
        namesVaasVector.push_back(oneName);
    }
    inputFile.close();

    return namesVaasVector;
}

std::vector<std::string> FactoryRandom::namesJasonPush(){
    std::vector<std::string> namesJasonVector;
    std::ifstream inputFile("../../unicNames/jason.txt");

    std::string oneName;

    while (std::getline(inputFile, oneName)) {
        namesJasonVector.push_back(oneName);
    }
    inputFile.close();

    return namesJasonVector;
}

std::vector<std::string> FactoryRandom::namesBuckPush(){
    std::vector<std::string> namesBuckVector;
    std::ifstream inputFile("../../unicNames/buck.txt");

    std::string oneName;

    while (std::getline(inputFile, oneName)) {
        namesBuckVector.push_back(oneName);
    }
    inputFile.close();

    return namesBuckVector;
}

Point<int> FactoryRandom::getRandomPosition(){
    int coordX = std::rand() % mapWidth;
    int coordY = std::rand() % mapWidth;
    return Point(coordX, coordY);
}

std::string FactoryRandom::giveName(NPCType type, std::size_t countOfNPCType){
    switch (type)
    {
    case NPCType::VaasMontenegro:
        return namesVaas[countOfNPCType];
    
    case NPCType::JasonBrody:
        return namesJason[countOfNPCType];
    
    case NPCType::BuckHughes:
        return namesBuck[countOfNPCType];

    default:
        throw std::logic_error("Unknown NPC type");
    }
}

FactoryRandom::FactoryRandom(std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{}

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