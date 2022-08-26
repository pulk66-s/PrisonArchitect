#ifndef __OBJECT_WALL_BRICKWALL_HPP__
    #define __OBJECT_WALL_BRICKWALL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ATile.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class PA::Object::Tile::BrickWall : public PA::Object::Tile::ATile {

    public:
    BrickWall(PA::Vector2i index, PA::Vector2i pos);
    void update();

};

#endif