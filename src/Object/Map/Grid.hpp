#ifndef __PA_OBJECT_MAP_GRID_HPP__
    #define __PA_OBJECT_MAP_GRID_HPP__

    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Object/ObjectNamespace.hpp"
    #include "Global/Vector.hpp"
    #include <memory>

class PA::Object::Map::Grid {

    private:
    PA::Vector2i squareDim = {30, 30};
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Event> event = PA::Lib::SDL2::Event::getInstance();

    public:
    static std::shared_ptr<Grid> getInstance();
    PA::Vector2i getSquareDim();
    PA::Vector2i transformPos(PA::Vector2i pos);

};

#endif