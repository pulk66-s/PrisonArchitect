#ifndef __OBJECT_PNJ_IA_IA_HPP__
    #define __OBJECT_PNJ_IA_IA_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include <ctime>
    #include <cstdlib>
    #include <unordered_map>

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
    Move nextMove = NONE;

    public:
    void update();
    Move getMove();
};

#endif