#ifndef __LIB_SDL2_IMAGE_HPP__
    #define __LIB_SDL2_IMAGE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include "Lib/SDL2/Graphic/Texture.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <string>
    #include <memory>

    #include <stdlib.h>

class PA::Lib::SDL2::Graphic::Image {
    private:
    std::shared_ptr<PA::Lib::SDL2::Event> event = PA::Lib::SDL2::Event::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer = PA::Lib::SDL2::Renderer::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteManager> spriteManager = PA::Lib::SDL2::Graphic::SpriteManager::getInstance();

    std::string path;
    std::unique_ptr<PA::Lib::SDL2::Graphic::Texture> texture;
    PA::Vector2<int> pos = {0, 0}, dim = {0, 0};
    PA::Vector2<int> srcDim = {0, 0};
    PA::Vector2<int> nbSprite = {0, 0};
    PA::Vector2<int> currIndex = {0, 0};
    bool isSpriteSheet = false;
    PA::Lib::SDL2::Camera::Status status = PA::Lib::SDL2::Camera::Status::MOVABLE;

    public:
    Image(std::string path, PA::Vector2<int> dim, PA::Vector2<int> pos={0, 0}, bool isSpriteSheet=false, PA::Vector2<int> nbSprite={0, 0}, PA::Lib::SDL2::Camera::Status status=PA::Lib::SDL2::Camera::Status::MOVABLE);
    Image(SDL_Texture *texture);
    Image(const Image &other);
    bool draw();
    void setPosition(PA::Vector2<int> pos);
    void setDimensions(PA::Vector2<int> dim);
    PA::Vector2<int> getPosition();
    PA::Vector2<int> getDimensions();
    PA::Vector2<int> getIndex();
    void setIndex(PA::Vector2<int> index);
    void move(PA::Vector2<int> pos);
    bool isClick();
    bool isClickOutside();
    void setStatus(PA::Lib::SDL2::Camera::Status status);
};

#endif