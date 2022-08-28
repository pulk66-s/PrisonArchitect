#ifndef __OBJECT_WALL_BRICKWALL_HPP__
    #define __OBJECT_WALL_BRICKWALL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/Wall/AWall.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class PA::Object::Tile::Wall::Brick : public PA::Object::Tile::Wall::AWall {

    public:
    Brick(PA::Vector2i index, PA::Vector2i pos);

};

#endif