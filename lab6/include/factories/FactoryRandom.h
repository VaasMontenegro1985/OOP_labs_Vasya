#pragma once
#include <iostream>
#include "../NPC.h" 
#include "../vaas.h" 
#include "../buck.h" 
#include "../jason.h"
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>

class FactoryRandom {
    private:
        std::size_t mapWidth;
        std::size_t mapHeight;

        std::vector<std::string> namesJason;
        std::vector<std::string> namesBuck;
        std::vector<std::string> namesVaas;

        Point<int> getRandomPosition();
        std::string giveName(NPCType type, std::size_t countOfNPCType);

        public:
            std::vector<std::string> namesJasonPush();
            std::vector<std::string> namesBuckPush();
            std::vector<std::string> namesVaasPush();
            FactoryRandom(std::size_t width, std::size_t height);

            std::shared_ptr<NPC> CreateVaas();
            std::shared_ptr<NPC> CreateBuck();
            std::shared_ptr<NPC> CreateJason();

            
            std::shared_ptr<NPC> CreateNPC(NPCType type);
            std::shared_ptr<NPC> CreateRandomNPC();
};
