#include "Object/Menu/Notif/ANotif.hpp"

namespace PA::Object::Menu::Notif {

    ANotif::ANotif(std::string message, PA::Vector2<int> pos, PA::Vector2<int> dim) {
        this->message = message;
        this->text = std::make_unique<PA::Lib::SDL2::Graphic::Text>(message, pos, dim);
        this->text->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
        this->background = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            pos - PA::Vector2<int>(10, 10),
            dim + PA::Vector2<int>(20, 20),
            SDL_Color{0, 0, 0, 200},
            true, PA::Lib::SDL2::Camera::Status::FIXED
        );
        this->_isDone = false;
    }

    void ANotif::draw() {
        this->background->draw();
        this->text->draw();
    }

    void ANotif::update() {
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

    bool ANotif::isDone() const {
        return (this->_isDone);
    }

    void ANotif::setPos(PA::Vector2<int> pos) {
        this->background->setPos(pos - PA::Vector2<int>(10, 10));
        this->text->setPos(pos);
    }


}