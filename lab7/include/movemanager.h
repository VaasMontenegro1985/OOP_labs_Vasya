#pragma once
#include <set>
#include <memory>
#include <chrono>
#include <thread>
#include "npc.h"
#include "fightManager.h"

class MoveManager{
    private:
        std::size_t mapWidth;
        std::size_t mapHeight;

    public:
        MoveManager(std::size_t width, std::size_t height);

        void operator() (const bool &gameRunning, std::set<std::shared_ptr<NPC>> &npcs, FightManager &fightManager);
};