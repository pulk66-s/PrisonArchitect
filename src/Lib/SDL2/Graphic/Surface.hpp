#ifndef __PA_LIB_SDL2_GRAPHIC_SURFACE_HPP__
    #define __PA_LIB_SDL2_GRAPHIC_SURFACE_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Vector.hpp"
    #include <string>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>

class PA::Lib::SDL2::Graphic::Surface {
    
    private:
    SDL_Surface *surface;

    public:
    Surface(std::string path);
    ~Surface();
    SDL_Surface *getSurface();
    PA::Vector2<int> getDim();
    
};

#endif