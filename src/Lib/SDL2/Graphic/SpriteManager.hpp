#ifndef __LIB_SDL2_SPRITE_MANAGER_HPP__
    #define __LIB_SDL2_SPRITE_MANAGER_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>
    #include <iostream>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>

class PA::Lib::SDL2::Graphic::SpriteManager {

    private:
    std::unordered_map<std::string, SDL_Surface *> sprites;

    public:
    SpriteManager();
    ~SpriteManager();
    static std::shared_ptr<SpriteManager> getInstance();
    SDL_Surface *getSprite(std::string path);

};

#endif