#include "Object/Menu/Notif/Error.hpp"

namespace PA::Object::Menu::Notif {

    Error::Error(std::string message, PA::Vector2i pos, PA::Vector2i dim) {
        this->message = message;
        this->text = std::make_unique<PA::Lib::SDL2::Graphic::Text>(message, pos, dim);
        this->text->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
        this->text->setColor({200, 0, 0, 200});
        this->background = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            pos - PA::Vector2i(10, 10),
            dim + PA::Vector2i(20, 20),
            SDL_Color{0, 0, 0, 200},
            true, PA::Lib::SDL2::Camera::Status::FIXED
        );
        this->_isDone = false;
    }

    void Error::draw() {
        this->background->draw();
        this->text->draw();
    }

    void Error::update() {
        if (this->_isDone) {
            return;
        }
        SDL_Color color = this->text->getColor();
        if (color.a > 0) {
            color.a--;
            this->text->setColor(color);
        } else {
            this->_isDone = true;
        }
        color = this->background->getColor();
        if (color.a > 0) {
            color.a--;
            this->background->setColor(color);
        }
    }

    bool Error::isDone() const {
        return (this->_isDone);
    }

    void Error::setPos(PA::Vector2i pos) {
        this->background->setPos(pos - PA::Vector2i(10, 10));
        this->text->setPos(pos);
    }

}