#include "../include/game.h"
#include "../../include/factories/FactoryRandom.h"
#include "../../include/factories/FactoryFile.h"
#include <iostream>

Game::NPCSet Game::battle_step(double killDistance){
    NPCSet killed;

    for (const auto &attacker : units){
        for (const auto &defender : units){
            if (attacker == defender || !attacker->isClose(defender, killDistance)) continue;

            if (defender->accept(attacker)){
                killed.insert(defender);
            }
        }
    }
    return killed;
}
Game::Game(std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{

};
void Game::init(std::size_t quantity){
    units.clear();

    FactoryRandom factory(mapWidth, mapHeight);

    for (int i = 0; i < quantity; i++){
        auto npc = factory.CreateRandomNPC();
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
        auto npc = factory.CreateNPCFromFile();
        units.insert(npc);
    }
};
void Game::battle(double distanceBegin, double distanceEnd, double distanceStep){
    for (double killDistance = distanceBegin; killDistance < distanceEnd; killDistance + distanceStep){
        std::cout << "=====FIGHT CYCLE=====" << std::endl;
        std::cout << "Kill distance: " << killDistance << std::endl << std::endl;

        auto killed = battle_step(killDistance);

        for (auto &npc : killed){ units.erase(npc)};
    
        std::cout << std::endl;
    }
};

std::ostream& operator<<(std::ostream &os, Game &game){
    for (const auto &npc : game.units){
        os << *npc << std::endl;
    }
    os << std::endl;

    return os;
};