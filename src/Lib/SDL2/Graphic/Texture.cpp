#include "Lib/SDL2/Graphic/Texture.hpp"

namespace PA::Lib::SDL2::Graphic {
    
    Texture::Texture(std::string path) {
        std::shared_ptr<PA::Lib::SDL2::Graphic::Surface> surface = this->spriteManager->getSprite(path);
        this->texture = SDL_CreateTextureFromSurface(this->renderer->getRenderer(), surface->getSurface());
    }

    Texture::Texture(SDL_Texture *texture) {
        this->texture = texture;
    }

    Texture::~Texture() {
        SDL_DestroyTexture(this->texture);
    }
    
    SDL_Texture *Texture::getTexture() {
        return (this->texture);
    }

    PA::Vector2<int> Texture::getDim() {
        PA::Vector2<int> dim;
        SDL_QueryTexture(this->texture, NULL, NULL, &dim.x, &dim.y);
        return (dim);
    }

}