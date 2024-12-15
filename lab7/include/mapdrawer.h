#pragma once
#include "npc.h"
#include "printer.h"
#include <memory>
#include <vector>
#include <set>

class MapDrawer {
    private:
    std::size_t mapWidth;
    std::size_t mapHeight;

    public:
        MapDrawer (std::size_t width, std::size_t height);
        void operator() (std::set<std::shared_ptr<NPC>> &npcs);
};