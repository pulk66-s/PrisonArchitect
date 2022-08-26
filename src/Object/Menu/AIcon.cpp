#include "AIcon.hpp"

namespace KA::Object::Menu {

    AIcon::AIcon(KA::Vector2i pos, KA::Vector2i dim, KA::Vector2i index, std::string spritesheetPath)
    {
        this->spritesheetPath = spritesheetPath;
        this->pos = pos;
        this->dim = dim;
        this->roomImage = std::make_unique<KA::Lib::SDL2::Image>(
            "res/sprites/menu/game_ui.png",
            this->dim, this->pos,
            true, KA::Vector2i{3, 1}, KA::Lib::SDL2::Camera::Status::FIXED
        );
        this->roomImage->setIndex(index);
        this->menuBackground = std::make_unique<KA::Lib::SDL2::Shape::Rectangle>(
            KA::Vector2i{100, 600}, KA::Vector2i{400, 240},
            this->menuBackgroundColor, true, KA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    KA::Object::Menu::AIcon::Action AIcon::update() {
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