#include "Text.hpp"

namespace KA::Lib::SDL2 {

    Text::Text(std::string text, KA::Vector2i pos, KA::Vector2i dim, KA::Lib::SDL2::Camera::Status status, SDL_Color color, std::string font) {
        this->status = status;
        this->text = text;
        this->color = color;
        this->renderer = KA::Lib::SDL2::Renderer::getInstance();
        this->font = TTF_OpenFont(font.c_str(), 84);
        if (this->font == NULL) {
            std::cerr << "Erreur lors de l'ouverture de la police : " << TTF_GetError() << std::endl;
            throw KA::Error::InvalidArgument("Could not load font " + font, "Text::Text");
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
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer->get(), this->surface);
        SDL_Rect rect = {this->pos.x, this->pos.y, this->dim.x, this->dim.y};
        if (this->status == KA::Lib::SDL2::Camera::Status::MOVABLE) {
            std::shared_ptr<KA::Lib::SDL2::Camera> camera = KA::Lib::SDL2::Camera::getInstance();
            KA::Vector2i camPos = camera->getPos();
            rect.x -= camPos.x;
            rect.y -= camPos.y;
        }
        SDL_RenderCopy(this->renderer->get(), texture, NULL, &rect);
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

}
