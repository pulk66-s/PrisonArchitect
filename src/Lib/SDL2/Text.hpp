#ifndef __LIB_SDL2_TEXT_HPP__
    #define __LIB_SDL2_TEXT_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Renderer.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>

class KA::Lib::SDL2::Text {

    private:
    std::shared_ptr<KA::Lib::SDL2::Renderer> renderer;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Color color;
    KA::Vector2i pos, dim;
    KA::Lib::SDL2::Camera::Status status;
    std::string text;

    public:
    Text(std::string text, KA::Vector2i pos, KA::Vector2i dim, KA::Lib::SDL2::Camera::Status status=KA::Lib::SDL2::Camera::Status::MOVABLE, SDL_Color color={255, 255, 255, 255}, std::string font="res/font/arial.ttf");
    ~Text();
    void draw();
    void setText(std::string text);
    std::string getText();

};

#endif