#include "../include/fightManager.h"
#include <mutex>

#include <cstdlib>

void FightManager::addEvent(MurderEvent &&event){
    std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
};

void FightManager::organizeMurder(MurderEvent &event){
    if (!event.attacker->isAlive() || !event.defender->isAlive()) return;
    std::size_t attackPoints = std::rand() % 6 + 1;
    std::size_t defendPoints = std::rand() % 6 + 1;
    if (attackPoints > defendPoints) event.defender->kill();
};

void FightManager::operator()(const bool &gameRunning){
    while (gameRunning)
    {
        std::shared_lock<std::shared_mutex> lockRead(mtx);
        if (events.empty()) continue;

        lockRead.unlock();
        std::lock_guard<std::shared_mutex> lockWrite(mtx);
        organizeMurder(events.front());
        events.pop();
    }
};