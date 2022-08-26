#ifndef __OBJECT_WALL_BRICKWALL_HPP__
    #define __OBJECT_WALL_BRICKWALL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ATile.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class KA::Object::Tile::BrickWall : public KA::Object::Tile::ATile {

    public:
    BrickWall(KA::Vector2i index, KA::Vector2i pos);
    void update();

};

#endif