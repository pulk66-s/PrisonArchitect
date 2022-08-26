#ifndef __OBJECT_WALL_COLLIDER_HPP__
    #define __OBJECT_WALL_COLLIDER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Image.hpp"
    #include <exception>
    #include <bits/stdc++.h>

class PA::Object::Tile::ATile : public PA::Object::Tile::ITile {

    protected:
    bool colliding = false;
    std::shared_ptr<PA::Lib::SDL2::Graphic::Image> image = nullptr;
    std::shared_ptr<PA::Object::Grid> grid;
    std::string name = "";
    std::unordered_map<WallPosition, PA::Vector2i> wallPositions = {};

    public:
    ATile();
    ~ATile();
    bool isColliding();
    void draw();
    virtual void update() = 0;
    std::string getName();
    void setWallPosition(WallPosition position);
};

#endif