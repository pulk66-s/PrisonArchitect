#ifndef __OBJECT_ROOM_AROOM_HPP__
    #define __OBJECT_ROOM_AROOM_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include <vector>
    #include <memory>

class PA::Object::Tile::Room::ARoom {

    protected:
    PA::Vector2i dim = {1, 1}, pos = {0, 0};
    const PA::Vector2i gridDim = {30, 30};
    std::string name = "";
    std::vector<PA::Lib::SDL2::Shape::Rectangle> rectangles;
    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> text;

    public:
    ARoom(PA::Vector2i dim, PA::Vector2i pos={0,0}, std::string name="Unknown");
    void draw();

};

#endif