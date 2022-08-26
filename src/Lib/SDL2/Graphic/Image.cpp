#include "Image.hpp"

namespace PA::Lib::SDL2::Graphic {

    Image::Image(std::string path, PA::Vector2i dim, PA::Vector2i pos, bool isSpriteSheet, PA::Vector2i nbSprite, PA::Lib::SDL2::Camera::Status status)
    {
        this->status = status;
        this->path = path;
        this->renderer = PA::Lib::SDL2::Renderer::getInstance();
        this->spriteManager = PA::Lib::SDL2::Graphic::SpriteManager::getInstance();
        SDL_Surface *surface = this->spriteManager->getSprite(path);
        if (surface == NULL) {
            std::cerr << "Error: " << SDL_GetError() << std::endl;
            throw PA::Error::InvalidArgument("Image::Image", path);
        }
        this->texture = SDL_CreateTextureFromSurface(renderer->get(), surface);
        if (this->texture == NULL) {
            std::cerr << "Error: " << SDL_GetError() << std::endl;
            throw PA::Error::InvalidArgument("Image::Image", path);
        }
        this->dim = dim;
        this->pos = pos;
        this->textureDim = {surface->w, surface->h};
        if (isSpriteSheet) {
            this->isSpriteSheet = true;
            if (nbSprite.x == 0 || nbSprite.y == 0) {
                throw PA::Error::InvalidArgument("Invalid number of sprite", "PA::Lib::SDL2::Graphic::Image::Image");
            } else {
                this->nbSprite = nbSprite;
                this->srcDim = {this->textureDim.x / nbSprite.x, this->textureDim.y / nbSprite.y};
            }
        }
        this->event = PA::Lib::SDL2::Event::getInstance();
    }

    Image::Image(SDL_Texture *texture) {
        this->texture = texture;
        this->renderer = PA::Lib::SDL2::Renderer::getInstance();
    }

    Image::Image(const Image &other)
    : Image(other.path, other.dim, other.pos, other.isSpriteSheet, other.nbSprite, other.status) {
        this->currIndex = other.currIndex;
    }

    Image::~Image() {
        SDL_DestroyTexture(this->texture);
    }

    bool Image::draw() {
        SDL_Rect rect = {this->pos.x, this->pos.y, this->dim.x, this->dim.y};
        if (this->status == PA::Lib::SDL2::Camera::Status::MOVABLE) {
            std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
            PA::Vector2i camPos = camera->getPos();
            rect.x -= camPos.x;
            rect.y -= camPos.y;
        }
        if (this->isSpriteSheet) {
            PA::Vector2i srcPos = {this->currIndex.x * this->srcDim.x, this->currIndex.y * this->srcDim.y};
            SDL_Rect src = {srcPos.x, srcPos.y, this->srcDim.x, this->srcDim.y};
            return (SDL_RenderCopy(this->renderer->get(), this->texture, &src, &rect) == 0);
        } else {
            return (SDL_RenderCopy(this->renderer->get(), this->texture, NULL, &rect) == 0);
        }
    }

    void Image::setPosition(PA::Vector2i pos) {
        this->pos = pos;
    }

    void Image::setDimensions(PA::Vector2i dim) {
        this->dim = dim;
    }

    PA::Vector2i Image::getPosition() {
        return (this->pos);
    }

    PA::Vector2i Image::getDimensions() {
        return (this->dim);
    }

    SDL_Texture *Image::getTexture() {
        return (this->texture);
    }

    void Image::setIndex(PA::Vector2i index) {
        if (this->isSpriteSheet) {
            this->currIndex = index;
        } else {
            throw PA::Error::InvalidArgument("Image is not a sprite sheet", "PA::Lib::SDL2::Graphic::Image::setIndex");
        }
    }

    void Image::move(PA::Vector2i pos) {
        this->pos.x += pos.x;
        this->pos.y += pos.y;
    }

    bool Image::isClick() {
        if (this->event->isClick()) {
            PA::Vector2i mousePos = this->event->getClickPosition();
            if (mousePos.x >= this->pos.x && mousePos.x <= this->pos.x + this->dim.x) {
                if (mousePos.y >= this->pos.y && mousePos.y <= this->pos.y + this->dim.y) {
                    return (true);
                }
            }
        }
        return (false);
    }

    bool Image::isClickOutside() {
        if (this->event->isClick()) {
            PA::Vector2i mousePos = this->event->getClickPosition();
            if (mousePos.x < this->pos.x || mousePos.x > this->pos.x + this->dim.x) {
                return (true);
            }
            if (mousePos.y < this->pos.y || mousePos.y > this->pos.y + this->dim.y) {
                return (true);
            }
        }
        return (false);
    }

    void Image::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->status = status;
    }

    PA::Vector2i Image::getIndex() {
        return (this->currIndex);
    }

}
