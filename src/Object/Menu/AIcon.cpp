#include "AIcon.hpp"

namespace PA::Object::Menu {

    AIcon::AIcon(PA::Vector2<int> pos, PA::Vector2<int> dim, PA::Vector2<int> index, std::string spritesheetPath)
    {
        this->spritesheetPath = spritesheetPath;
        this->pos = pos;
        this->dim = dim;
        this->roomImage = std::make_unique<PA::Lib::SDL2::Graphic::Image>(
            "res/sprites/menu/game_ui.png",
            this->dim, this->pos,
            true, PA::Vector2<int>{3, 1}, PA::Lib::SDL2::Camera::Status::FIXED
        );
        this->roomImage->setIndex(index);
        this->menuBackground = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2<int>{100, 600}, PA::Vector2<int>{400, 240},
            this->menuBackgroundColor, true, PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    PA::Object::Menu::AIcon::Action AIcon::update() {
        if (this->roomImage->isClick()) {
            this->displayed = true;
        } else if (this->roomImage->isClickOutside() && this->menuBackground->isClickOutside()) {
            this->displayed = false;
        }
        return (NONE);
    }

    void AIcon::draw() {
        this->roomImage->draw();
        if (this->displayed) {
            this->menuBackground->draw();
            for (auto &icon : this->roomIcons) {
                icon.second.icon->draw();
                icon.second.text->draw();
            }
        }
    }

    bool AIcon::isDisplayed() {
        return (this->displayed);
    }

}