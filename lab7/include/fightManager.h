#pragma once
#include <queue>
#include <mutex>
#include "npc.h"


class FightManager
{
public:
    struct MurderEvent{
        std::shared_ptr<NPC> attacker;
        std::shared_ptr<NPC> defender;

        MurderEvent (std::shared_ptr<NPC> attackerPtr, std::shared_ptr<NPC> defenderPtr) :
            attacker{attackerPtr}, defender{defenderPtr} {};
    };
    void addEvent(MurderEvent &&event);
    void operator()(const bool &gameRunning);
    FightManager() = default;
    
private:
    std::queue<MurderEvent> events;
    std::shared_mutex mtx;


    void organizeMurder(MurderEvent &event);
};
