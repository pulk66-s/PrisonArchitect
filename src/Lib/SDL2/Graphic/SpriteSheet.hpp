#ifndef __PA_LIB_SDL2_SPRITESHEET_HPP__
    #define __PA_LIB_SDL2_SPRITESHEET_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Graphic/Texture.hpp"
    #include "Global/Vector.hpp"

class PA::Lib::SDL2::Graphic::SpriteSheet {

    private:
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer = PA::Lib::SDL2::Renderer::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();

    std::shared_ptr<PA::Lib::SDL2::Graphic::Texture> texture;
    PA::Vector2i srcPos = {0, 0}, srcDim = {0, 0};
    SDL_Rect src = {0, 0, 0, 0};
    PA::Vector2i nbSprite = {0, 0};
    PA::Vector2i pos = {0, 0}, dim = {0, 0};
    PA::Vector2i currIndex = {0, 0};
    PA::Lib::SDL2::Camera::Status status = PA::Lib::SDL2::Camera::Status::MOVABLE;

    public:
    SpriteSheet(std::string path, PA::Vector2i nbSprite, PA::Vector2i pos, PA::Vector2i dim, PA::Lib::SDL2::Camera::Status status = PA::Lib::SDL2::Camera::Status::MOVABLE);
    void draw();
    void setIndex(PA::Vector2i index);
    void setPosition(PA::Vector2i pos);

};

#endif