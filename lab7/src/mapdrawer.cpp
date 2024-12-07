#include "../include/mapdrawer.h"

MapDrawer::MapDrawer (std::size_t width, std::size_t height) : mapWidth{width}, mapHeight{height}{};
void MapDrawer::operator() (std::set<std::shared_ptr<NPC>> &npcs){
    Printer printer;

    std::vector<char>cells(mapWidth * mapHeight, ' ');

    for (auto const &npc : npcs){
        if (!npc->isAlive()) continue;

        Point coords = npc->getCoords();
        cells[coords.getX() + coords.getY() * mapWidth] = npc->getSprite();
    }
    for (std::size_t y = 0; y < mapHeight; y++){
        for (std::size_t x = 0; x < mapWidth; x++){
        printer << "[" << cells[x + mapWidth * y] << "]";
    }
    printer << '\n';
    }
    printer << '\n';

};