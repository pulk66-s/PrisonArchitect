    #ifndef __LIB_SDL2_RECTANGLE_HPP__
    #define __LIB_SDL2_RECTANGLE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Vector.hpp"
    #include <memory>
    #include <iostream>

class PA::Lib::SDL2::Shape::Rectangle {
    private:
    PA::Lib::SDL2::Camera::Status status = PA::Lib::SDL2::Camera::Status::MOVABLE;
    std::unique_ptr<SDL_Rect> rectangle;
    std::unique_ptr<SDL_Color> color;
    bool isFilled = true;
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer;
    std::shared_ptr<PA::Lib::SDL2::Event> event;
    PA::Vector2i pos, dim;

    public:
    Rectangle(PA::Vector2i pos, PA::Vector2i dim, SDL_Color color, bool isFilled=false, PA::Lib::SDL2::Camera::Status status=PA::Lib::SDL2::Camera::Status::MOVABLE);
    bool draw();
    bool isClick();
    bool isClickOutside();
    void setDim(PA::Vector2i dim);
    void setPos(PA::Vector2i pos);
    PA::Vector2i getDim();
    PA::Vector2i getPos() const;
    void setStatus(PA::Lib::SDL2::Camera::Status status);
    void setColor(SDL_Color color);
    SDL_Color getColor() const;
};

#endif