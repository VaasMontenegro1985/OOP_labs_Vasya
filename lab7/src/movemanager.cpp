#include "../include/movemanager.h"
#include "../include/fightManager.h"
#include "../include/npc.h"

using namespace std::chrono_literals;
MoveManager::MoveManager(std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{};

void MoveManager::operator() (const bool &gameRunning, std::set<std::shared_ptr<NPC>> &npcs, FightManager &fightManager){
    while (gameRunning){
        for (const auto &npc : npcs){
            if (npc->isAlive()) npc->move(mapWidth, mapHeight);
        }

        for (const auto &attacker : npcs){
        for (const auto &defender : npcs){
            if (!attacker->isAlive() || !defender->isAlive()) continue;
            if (attacker == defender || !attacker->isClose(defender) || !defender->accept(attacker)) continue;

            fightManager.addEvent(FightManager::MurderEvent(attacker, defender));
            }
        }
        std::this_thread::sleep_for(250ms);
    }
};