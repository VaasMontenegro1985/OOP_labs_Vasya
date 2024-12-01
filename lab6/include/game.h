#pragma once

class Game
{
private:
    using NPCSet = std::set<std::shared_ptr<NPC>>;

    std::size_t mapWidth;
    std::size_t mapHeight;
    NPCSet units;

    NPCSet battle_step (double killdistance);
public:
    Game(std::size_t mapWidth, std::size_t mapHeight;);
    void init(std::size_t quantity);
    void saveState(std::string filename){};
    void loadState(std::string filename){};
    void battle (){};

    std::ostream& operator<<(std::ostream &os, Game &game){};
};