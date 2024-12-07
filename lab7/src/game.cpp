#include "../include/game.h"
#include "../include/factories/FactoryRandom.h"
#include "../include/printer.h"
#include "../include/factories/FactoryFile.h"
#include <iostream>

using namespace std::chrono_literals;
Game::Game(std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{
    screenOut = std::make_shared<ObserverStdout>();
    fileOut = std::make_shared<ObserverFile>("log.txt");
};
void Game::init(std::size_t quantity){

    units.clear();

    FactoryRandom factory(mapWidth, mapHeight);
    for (int i = 0; i < quantity; i++){
        auto npc = factory.CreateRandomNPC();
        npc->subscribe(screenOut);
        npc->subscribe(fileOut);
        units.insert(npc);
    }
};
void Game::saveState(std::string filename){
    FactoryFile::NPCSaver saver(filename, units.size());

    for (const auto &npc : units){
        saver.saveNPC(npc);
    }
};
void Game::loadState(std::string filename){
    units.clear();

    FactoryFile factory(filename);

    while (!factory.endOfFile()){
        auto npc = factory.createNPCFromFile();
        
        npc->subscribe(screenOut);
        npc->subscribe(fileOut);
        units.insert(npc);
    }
};
void Game::battle(){
    bool gameRunning = true;
    
    FightManager fightManager;
    MoveManager moveManager(mapWidth, mapHeight);
    MapDrawer mapDrawer(mapWidth, mapHeight);

    mapDrawer(units);
    std::thread fightThread(std::ref(fightManager), std::ref(gameRunning));
    std::thread moveThread(std::ref(moveManager), std::ref(gameRunning), std::ref(units), std::ref(fightManager));

    std::size_t frames = 0;
    while (frames++ <30){
        std::this_thread::sleep_for(1s);
        mapDrawer(units);
    }

    gameRunning = false;
    moveThread.join();
    fightThread.join();
};

std::ostream& operator<<(std::ostream &os, Game &game){
    for (const auto &npc : game.units){
        if (npc->isAlive()) os << *npc << std::endl;
    }
    os << std::endl;

    return os;
};