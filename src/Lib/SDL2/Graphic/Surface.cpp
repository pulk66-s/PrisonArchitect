#include "Lib/SDL2/Graphic/Surface.hpp"

namespace PA::Lib::SDL2::Graphic {

    Surface::Surface(std::string path) {
        this->surface = IMG_Load(path.c_str());
        if (this->surface == NULL) {
            throw PA::Error::InvalidArgument("Could not load surface " + path, __FILE__);
        }
    }

    Surface::~Surface() {
        SDL_FreeSurface(this->surface);
    }

    SDL_Surface *Surface::getSurface() {
        return (this->surface);
    }

    PA::Vector2<int> Surface::getDim() {
        return (PA::Vector2<int>(this->surface->w, this->surface->h));
    }

}