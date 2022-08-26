#ifndef __LIB_SDL2_IMAGE_HPP__
    #define __LIB_SDL2_IMAGE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <string>
    #include <memory>

    #include <stdlib.h>

class PA::Lib::SDL2::Graphic::Image {
    private:
    std::shared_ptr<PA::Lib::SDL2::Event> event = nullptr;

    std::string path;
    SDL_Texture *texture;
    PA::Vector2i pos = {0, 0}, dim = {0, 0};
    PA::Vector2i srcDim = {0, 0};
    PA::Vector2i textureDim = {0, 0};
    PA::Vector2i nbSprite = {0, 0};
    PA::Vector2i currIndex = {0, 0};
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer = nullptr;
    bool isSpriteSheet = false;
    PA::Lib::SDL2::Camera::Status status = PA::Lib::SDL2::Camera::Status::MOVABLE;
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteManager> spriteManager = nullptr;

    public:
    Image(std::string path, PA::Vector2i dim, PA::Vector2i pos={0, 0}, bool isSpriteSheet=false, PA::Vector2i nbSprite={0, 0}, PA::Lib::SDL2::Camera::Status status=PA::Lib::SDL2::Camera::Status::MOVABLE);
    Image(SDL_Texture *texture);
    Image(const Image &other);
    ~Image();
    bool draw();
    void setPosition(PA::Vector2i pos);
    void setDimensions(PA::Vector2i dim);
    PA::Vector2i getPosition();
    PA::Vector2i getDimensions();
    PA::Vector2i getIndex();
    SDL_Texture *getTexture();
    void setIndex(PA::Vector2i index);
    void move(PA::Vector2i pos);
    bool isClick();
    bool isClickOutside();
    void setStatus(PA::Lib::SDL2::Camera::Status status);
};

#endif