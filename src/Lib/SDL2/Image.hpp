#ifndef __LIB_SDL2_IMAGE_HPP__
    #define __LIB_SDL2_IMAGE_HPP__

    #include "SDL2Namespace.hpp"
    #include "Renderer.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/SpriteManager.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <string>
    #include <memory>

    #include <stdlib.h>

class KA::Lib::SDL2::Image {
    private:
    std::shared_ptr<KA::Lib::SDL2::Event> event = nullptr;

    std::string path;
    SDL_Texture *texture;
    KA::Vector2i pos = {0, 0}, dim = {0, 0};
    KA::Vector2i srcDim = {0, 0};
    KA::Vector2i textureDim = {0, 0};
    KA::Vector2i nbSprite = {0, 0};
    KA::Vector2i currIndex = {0, 0};
    std::shared_ptr<KA::Lib::SDL2::Renderer> renderer = nullptr;
    bool isSpriteSheet = false;
    KA::Lib::SDL2::Camera::Status status = KA::Lib::SDL2::Camera::Status::MOVABLE;
    std::shared_ptr<KA::Lib::SDL2::SpriteManager> spriteManager = nullptr;

    public:
    Image(std::string path, KA::Vector2i dim, KA::Vector2i pos={0, 0}, bool isSpriteSheet=false, KA::Vector2i nbSprite={0, 0}, KA::Lib::SDL2::Camera::Status status=KA::Lib::SDL2::Camera::Status::MOVABLE);
    Image(SDL_Texture *texture);
    Image(const Image &other);
    ~Image();
    bool draw();
    void setPosition(KA::Vector2i pos);
    void setDimensions(KA::Vector2i dim);
    KA::Vector2i getPosition();
    KA::Vector2i getDimensions();
    KA::Vector2i getIndex();
    SDL_Texture *getTexture();
    void setIndex(KA::Vector2i index);
    void move(KA::Vector2i pos);
    bool isClick();
    bool isClickOutside();
    void setStatus(KA::Lib::SDL2::Camera::Status status);
};

#endif