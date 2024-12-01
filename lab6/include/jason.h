#pragma once
#include "npc.h"

class Jason : public NPC
{   
    private:
        size_t count;
    public:
        Jason(Point<int> coords, std::string name);
        size_t getCount();
        bool fight(const Vaas &other) override;
        bool fight(const Buck &other) override;
        bool fight(const Jason &other) override;
        bool accept (std::shared_ptr<NPC> other) override;
        std::ostream& print (std::ostream &os) override;
        friend std::ostream &operator<<(std::ostream &os, Jason &jason);
};