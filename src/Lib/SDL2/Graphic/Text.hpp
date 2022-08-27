#ifndef __LIB_SDL2_TEXT_HPP__
    #define __LIB_SDL2_TEXT_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>

class PA::Lib::SDL2::Graphic::Text {

    private:
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Color color;
    PA::Vector2i pos, dim;
    PA::Lib::SDL2::Camera::Status status;
    std::string text;

    public:
    Text(std::string text, PA::Vector2i pos, PA::Vector2i dim, PA::Lib::SDL2::Camera::Status status=PA::Lib::SDL2::Camera::Status::MOVABLE, SDL_Color color={255, 255, 255, 255}, std::string font="res/font/arial.ttf");
    ~Text();
    void draw();
    void setColor(SDL_Color color);
    SDL_Color getColor();
    void setText(std::string text);
    std::string getText();
    void setStatus(PA::Lib::SDL2::Camera::Status status);
    void setPos(PA::Vector2i pos);

};

#endif