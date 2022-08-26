#ifndef __LIB_SDL2__CAMERA_HPP__
    #define __LIB_SDL2__CAMERA_HPP__

    #include "SDL2Namespace.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include <memory>

class KA::Lib::SDL2::Camera {

    private:
    KA::Vector2i position, moveDirection;
    std::shared_ptr<KA::Lib::SDL2::Event> event;
    KA::Vector2i speed = {2, 2};

    public:
    typedef enum Status_e {
        FIXED,
        MOVABLE
    } Status;
    Camera();
    KA::Vector2i getPos();
    void setPos(KA::Vector2i pos);
    void move(KA::Vector2i pos);
    void update();
    static std::shared_ptr<KA::Lib::SDL2::Camera> getInstance();

};

#endif