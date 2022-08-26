#ifndef __LIB_SDL2__CAMERA_HPP__
    #define __LIB_SDL2__CAMERA_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include <memory>

class PA::Lib::SDL2::Camera {

    private:
    PA::Vector2i position, moveDirection;
    std::shared_ptr<PA::Lib::SDL2::Event> event;
    PA::Vector2i speed = {2, 2};

    public:
    typedef enum Status_e {
        FIXED,
        MOVABLE
    } Status;
    Camera();
    PA::Vector2i getPos();
    void setPos(PA::Vector2i pos);
    void move(PA::Vector2i pos);
    void update();
    static std::shared_ptr<PA::Lib::SDL2::Camera> getInstance();

};

#endif