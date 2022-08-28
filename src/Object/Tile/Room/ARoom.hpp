#ifndef __PA_OBJECT_ROOM_AROOM_HPP__
    #define __PA_OBJECT_ROOM_AROOM_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ATile.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <vector>
    #include <memory>

class PA::Object::Tile::Room::ARoom : public PA::Object::Tile::ATile {

    protected:
    std::vector<PA::Lib::SDL2::Shape::Rectangle> backGround = {};
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();

    public:
    ARoom(__attribute__((unused))PA::Vector2<int> index, PA::Vector2<int> pos, std::string name);
    void update();
    void draw();
    void setPos(PA::Vector2<int> pos);
    PA::Vector2<int> getPos() const;

};

#endif