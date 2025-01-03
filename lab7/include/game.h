#pragma once
#include "npc.h" 
#include "vaas.h" 
#include "buck.h" 
#include "jason.h"
#include <set>
#include <thread>
#include <ostream>
#include <memory>
#include "factories/FactoryFile.h"
#include "factories/FactoryRandom.h"
#include "observers/ObserverFile.h"
#include "observers/ObserverStdout.h"
#include "mapdrawer.h"
#include "fightManager.h"
#include "movemanager.h"
class Game
{
private:
    using NPCSet = std::set<std::shared_ptr<NPC>>;

    std::size_t mapWidth;
    std::size_t mapHeight;
    NPCSet units;

    std::shared_ptr<ObserverStdout> screenOut{nullptr};
    std::shared_ptr<ObserverFile> fileOut{nullptr};

public:
    Game(std::size_t mapWidth, std::size_t mapHeight);
    void init(std::size_t quantity);
    void saveState(std::string filename);
    void loadState(std::string filename);
    void battle();

    friend std::ostream& operator<<(std::ostream &os, Game &game);
};

std::ostream& operator<<(std::ostream &os, Game &game);