#ifndef __PA_LIB_SDL2_GRAPHIC_TEXTURE_HPP__
    #define __PA_LIB_SDL2_GRAPHIC_TEXTURE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Vector.hpp"
    #include <SDL2/SDL.h>

class PA::Lib::SDL2::Graphic::Texture {
    
    private:
    SDL_Texture *texture;
    std::shared_ptr<PA::Lib::SDL2::Renderer> renderer = PA::Lib::SDL2::Renderer::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteManager> spriteManager = PA::Lib::SDL2::Graphic::SpriteManager::getInstance();

    public:
    Texture(std::string path);
    Texture(SDL_Texture *texture);
    ~Texture();
    SDL_Texture *getTexture();
    PA::Vector2i getDim();

};

#endif