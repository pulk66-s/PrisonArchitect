#ifndef __OBJECT_PNJ_IA_IA_HPP__
    #define __OBJECT_PNJ_IA_IA_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Map/TileManager.hpp"

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
    std::shared_ptr<PA::Object::Map::Grid> grid;
    std::shared_ptr<PA::Object::Tile::TileManager> tileManager;
    Move nextMove = NONE;

    public:
    Ia();
    void update(PA::Vector2i pos);
    Move getMove();
};

#endif