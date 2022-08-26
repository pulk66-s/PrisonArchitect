    #ifndef __LIB_SDL2_RECTANGLE_HPP__
    #define __LIB_SDL2_RECTANGLE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Vector.hpp"
    #include <memory>
    #include <iostream>

class KA::Lib::SDL2::Shape::Rectangle {
    private:
    KA::Lib::SDL2::Camera::Status status = KA::Lib::SDL2::Camera::Status::MOVABLE;
    std::unique_ptr<SDL_Rect> rectangle;
    std::unique_ptr<SDL_Color> color;
    bool isFilled = true;
    std::shared_ptr<KA::Lib::SDL2::Renderer> renderer;
    std::shared_ptr<KA::Lib::SDL2::Event> event;
    KA::Vector2i pos, dim;

    public:
    Rectangle(KA::Vector2i pos, KA::Vector2i dim, SDL_Color color, bool isFilled=false, KA::Lib::SDL2::Camera::Status status=KA::Lib::SDL2::Camera::Status::MOVABLE);
    bool draw();
    bool isClick();
    bool isClickOutside();
    void setDim(KA::Vector2i dim);
    void setPos(KA::Vector2i pos);
    KA::Vector2i getDim();
    KA::Vector2i getPos();
    void setStatus(KA::Lib::SDL2::Camera::Status status);
};

#endif