#ifndef __OBJECT_WALL_COLLIDER_HPP__
    #define __OBJECT_WALL_COLLIDER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include <exception>

class PA::Object::Tile::ATile : public PA::Object::Tile::ITile {

    protected:
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();

    bool colliding = false;
    std::string name = "";
    int price = 0;

    public:
    bool isColliding();
    virtual void draw() = 0;
    void setColliding(bool colliding);
    virtual void update() = 0;
    std::string getName() const;
    int getPrice() const;
};

#endif