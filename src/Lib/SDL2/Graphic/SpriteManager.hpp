#ifndef __LIB_SDL2_SPRITE_MANAGER_HPP__
    #define __LIB_SDL2_SPRITE_MANAGER_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>
    #include <iostream>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>

class PA::Lib::SDL2::Graphic::SpriteManager {

    private:
    std::unordered_map<std::string, std::shared_ptr<PA::Lib::SDL2::Graphic::Surface>> sprites;

    public:
    SpriteManager();
    static std::shared_ptr<SpriteManager> getInstance();
    std::shared_ptr<PA::Lib::SDL2::Graphic::Surface> getSprite(std::string path);

};

#endif