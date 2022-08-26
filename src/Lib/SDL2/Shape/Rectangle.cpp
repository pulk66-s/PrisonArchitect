#include "Rectangle.hpp"

namespace PA::Lib::SDL2::Shape {

    Rectangle::Rectangle(PA::Vector2i pos, PA::Vector2i dim, SDL_Color color, bool isFilled, PA::Lib::SDL2::Camera::Status status) {
        this->rectangle = std::make_unique<SDL_Rect>();
        this->color = std::make_unique<SDL_Color>();
        this->pos = pos;
        this->dim = dim;
        this->rectangle->x = this->pos.x;
        this->rectangle->y = this->pos.y;
        this->rectangle->w = this->dim.x;
        this->rectangle->h = this->dim.y;
        this->color->r = color.r;
        this->color->g = color.g;
        this->color->b = color.b;
        this->color->a = color.a;
        this->renderer = PA::Lib::SDL2::Renderer::getInstance();
        this->event = PA::Lib::SDL2::Event::getInstance();
        this->isFilled = isFilled;
        this->status = status;
    }

    bool Rectangle::draw()
    {
        SDL_Rect finalRect = *this->rectangle;
        if (this->status == PA::Lib::SDL2::Camera::Status::MOVABLE) {
            std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
            PA::Vector2i cameraPos = camera->getPos();
            finalRect.x -= cameraPos.x;
            finalRect.y -= cameraPos.y;
        }
        if (SDL_SetRenderDrawColor(this->renderer->getRenderer(), this->color->r, this->color->g, this->color->b, this->color->a) != 0) {
            std::cerr << "SDL_SetRenderDrawColor Error: " << SDL_GetError() << std::endl;
            return (false);
        }
        if (this->isFilled) {
            if (SDL_RenderFillRect(this->renderer->getRenderer(), &finalRect) != 0) {
                std::cerr << "SDL_RenderFillRect Error: " << SDL_GetError() << std::endl;
                return (false);
            }
        } else {
            if (SDL_RenderDrawRect(this->renderer->getRenderer(), &finalRect) != 0) {
                std::cerr << "SDL_RenderDrawRect Error: " << SDL_GetError() << std::endl;
                return (false);
            }
        }
        return (true);
    }

    bool Rectangle::isClick()
    {
        if (this->event->isClick()) {
            PA::Vector2i click = this->event->getClickPosition();
            if (click.x >= this->pos.x && click.x <= this->pos.x + this->dim.x && click.y >= this->pos.y && click.y <= this->pos.y + this->dim.y) {
                return (true);
            }
        }
        return (false);
    }

    bool Rectangle::isClickOutside()
    {
        if (this->event->isClick()) {
            PA::Vector2i click = this->event->getClickPosition();
            if (click.x < this->pos.x || click.x > this->pos.x + this->dim.x || click.y < this->pos.y || click.y > this->pos.y + this->dim.y) {
                return (true);
            }
        }
        return (false);
    }

    void Rectangle::setDim(PA::Vector2i dim)
    {
        this->dim = dim;
        this->rectangle->w = this->dim.x;
        this->rectangle->h = this->dim.y;
    }

    void Rectangle::setPos(PA::Vector2i pos)
    {
        this->pos = pos;
        this->rectangle->x = this->pos.x;
        this->rectangle->y = this->pos.y;
    }

    PA::Vector2i Rectangle::getDim()
    {
        return (this->dim);
    }

    PA::Vector2i Rectangle::getPos()
    {
        PA::Vector2i finalPos = this->pos;
        if (this->status == PA::Lib::SDL2::Camera::Status::MOVABLE) {
            std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
            PA::Vector2i cameraPos = camera->getPos();
            finalPos.x += cameraPos.x;
            finalPos.y += cameraPos.y;
        }
        return (finalPos);
    }

    void Rectangle::setStatus(PA::Lib::SDL2::Camera::Status status)
    {
        this->status = status;
    }

}
