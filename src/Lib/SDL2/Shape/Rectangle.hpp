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
    PA::Vector2<int> pos, dim;

    public:
    Rectangle(PA::Vector2<int> pos, PA::Vector2<int> dim, SDL_Color color, bool isFilled=false, PA::Lib::SDL2::Camera::Status status=PA::Lib::SDL2::Camera::Status::MOVABLE);
    bool draw();
    bool isClick();
    bool isClickOutside();
    void setDim(PA::Vector2<int> dim);
    void setPos(PA::Vector2<int> pos);
    PA::Vector2<int> getDim();
    PA::Vector2<int> getPos() const;
    void setStatus(PA::Lib::SDL2::Camera::Status status);
    void setColor(SDL_Color color);
    SDL_Color getColor() const;
};

#endif