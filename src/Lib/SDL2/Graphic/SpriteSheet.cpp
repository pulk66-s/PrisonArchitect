#include "Lib/SDL2/Graphic/SpriteSheet.hpp"

namespace PA::Lib::SDL2::Graphic {
    
    SpriteSheet::SpriteSheet(std::string path, PA::Vector2i nbSprite, PA::Vector2i pos, PA::Vector2i dim, PA::Lib::SDL2::Camera::Status status) {
        this->texture = std::make_shared<PA::Lib::SDL2::Graphic::Texture>(path);
        this->nbSprite = nbSprite;
        this->pos = pos;
        this->status = status;
        this->srcDim = this->texture->getDim() / nbSprite;
        this->dim = dim;
        this->srcPos = this->currIndex * this->srcDim;
        this->src = {this->srcPos.x, this->srcPos.y, this->srcDim.x, this->srcDim.y};
    }

    void SpriteSheet::draw() {
        SDL_Rect rect = {this->pos.x, this->pos.y, this->dim.x, this->dim.y};
        if (this->status == PA::Lib::SDL2::Camera::Status::MOVABLE) {
            this->camera->applyCamera(&rect);
        }
        SDL_RenderCopy(this->renderer->getRenderer(), this->texture->getTexture(), &this->src, &rect);
    }

    void SpriteSheet::setIndex(PA::Vector2i index) {
        this->currIndex = index;
        this->srcPos = this->currIndex * this->srcDim;
        this->src = {this->srcPos.x, this->srcPos.y, this->srcDim.x, this->srcDim.y};
    }

    void SpriteSheet::setPos(PA::Vector2i pos) {
        this->pos = pos;
    }

    PA::Vector2i SpriteSheet::getPos() {
        return (this->pos);
    }

    void SpriteSheet::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->status = status;
    }

}