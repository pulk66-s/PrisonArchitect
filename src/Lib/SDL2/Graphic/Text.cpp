#include "Text.hpp"

namespace PA::Lib::SDL2::Graphic {

    Text::Text(std::string text, PA::Vector2<int> pos, PA::Vector2<int> dim, PA::Lib::SDL2::Camera::Status status, SDL_Color color, std::string font) {
        this->status = status;
        this->text = text;
        this->color = color;
        this->renderer = PA::Lib::SDL2::Renderer::getInstance();
        this->font = TTF_OpenFont(font.c_str(), 84);
        if (this->font == NULL) {
            std::cerr << "Erreur lors de l'ouverture de la police : " << TTF_GetError() << std::endl;
            throw PA::Error::InvalidArgument("Could not load font " + font, "Text::Text");
        }
        this->surface = TTF_RenderText_Blended(this->font, text.c_str(), color);
        this->dim = dim;
        this->pos = pos;
    }

    Text::~Text() {
        SDL_FreeSurface(this->surface);
        TTF_CloseFont(this->font);
    }

    void Text::draw() {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer->getRenderer(), this->surface);
        SDL_Rect rect = {this->pos.x, this->pos.y, this->dim.x, this->dim.y};
        if (this->status == PA::Lib::SDL2::Camera::Status::MOVABLE) {
            std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
            PA::Vector2<int> camPos = camera->getPos();
            rect.x -= camPos.x;
            rect.y -= camPos.y;
        }
        SDL_RenderCopy(this->renderer->getRenderer(), texture, NULL, &rect);
        SDL_DestroyTexture(texture);
    }

    void Text::setText(std::string text) {
        this->text = text;
        SDL_FreeSurface(this->surface);
        this->surface = TTF_RenderText_Blended(this->font, text.c_str(), this->color);
    }

    std::string Text::getText() {
        return (this->text);
    }

    void Text::setColor(SDL_Color color) {
        this->color = color;
        SDL_FreeSurface(this->surface);
        this->surface = TTF_RenderText_Blended(this->font, this->text.c_str(), this->color);
    }

    void Text::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->status = status;
    }

    SDL_Color Text::getColor() {
        return (this->color);
    }

    void Text::setPos(PA::Vector2<int> pos) {
        this->pos = pos;
    }

}
