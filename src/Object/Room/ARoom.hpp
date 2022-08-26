#ifndef __OBJECT_ROOM_AROOM_HPP__
    #define __OBJECT_ROOM_AROOM_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include <vector>
    #include <memory>

class KA::Object::Room::ARoom {

    protected:
    KA::Vector2i dim = {1, 1}, pos = {0, 0};
    const KA::Vector2i gridDim = {30, 30};
    std::string name = "";
    std::vector<KA::Lib::SDL2::Shape::Rectangle> rectangles;
    std::unique_ptr<KA::Lib::SDL2::Text> text;

    public:
    ARoom(KA::Vector2i dim, KA::Vector2i pos={0,0}, std::string name="Unknown");
    void draw();

};

#endif