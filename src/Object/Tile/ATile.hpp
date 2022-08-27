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
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet = nullptr;
    std::string name = "";
    std::unordered_map<WallPosition, PA::Vector2i> wallPositions = {};
    int price = 0;

    public:
    bool isColliding();
    void draw();
    void setColliding(bool colliding);
    void setPos(PA::Vector2i position);
    PA::Vector2i getPos() const;
    virtual void update() = 0;
    std::string getName();
    void setWallPosition(WallPosition position);
    void setStatus(PA::Lib::SDL2::Camera::Status status);
    PA::Vector2i getWallPosition(WallPosition position);
    bool operator<(const ATile& tile) const;
    int getPrice();
};

#endif