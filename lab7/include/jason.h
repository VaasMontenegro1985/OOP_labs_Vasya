#pragma once
#include "npc.h"
#include "buck.h"
#include "vaas.h"

class Jason : public NPC
{   
    private:
        static std::size_t count;
    public:
        Jason(Point<int> coords, std::string name);
        static std::size_t getCount();
        bool fight(const Vaas &other) override;
        bool fight(const Buck &other) override;
        bool fight(const Jason &other) override;
        bool accept (std::shared_ptr<NPC> other) override;


        std::ostream& print (std::ostream &os) override;
        friend std::ostream &operator<<(std::ostream &os, Jason &jason);
};