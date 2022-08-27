#ifndef __OBJECT_PNJ_IA_IA_HPP__
    #define __OBJECT_PNJ_IA_IA_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/TileManager.hpp"
    #include <ctime>
    #include <cstdlib>

class PA::Object::PNJ::IA::Ia {

    public:
    enum Move {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    protected:
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    std::shared_ptr<PA::Object::Tile::TileManager> tileManager = PA::Object::Tile::TileManager::getInstance();
    Move nextMove = NONE;

    public:
    void update(PA::Vector2i pos);
    Move getMove();
};

#endif