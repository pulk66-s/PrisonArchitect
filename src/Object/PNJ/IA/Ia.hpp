#ifndef __OBJECT_PNJ_IA_IA_HPP__
    #define __OBJECT_PNJ_IA_IA_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Map/TileManager.hpp"

class KA::Object::PNJ::IA::Ia {

    public:
    enum Move {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    protected:
    std::shared_ptr<KA::Object::Grid> grid;
    std::shared_ptr<KA::Object::TileManager> tileManager;
    Move nextMove = NONE;

    public:
    Ia();
    void update(KA::Vector2i pos);
    Move getMove();
};

#endif