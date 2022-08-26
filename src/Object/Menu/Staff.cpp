#include "Staff.hpp"

namespace PA::Object::Menu {

    Staff::Staff()
    : AIcon({170, 840}, {64, 64}, {1, 0}, "res/sprites/menu/staff_ui.png") {
        this->roomIcons["workman"] = CREATE_ICON("workman", 120, 620, 48, 48);
    }

    PA::Object::Menu::AIcon::Action Staff::update() {
        if (this->displayed) {
            if (this->roomIcons["workman"].icon->isClick()) {
                this->displayed = false;
                return (PA::Object::Menu::AIcon::Action::WORKMAN);
            }
        }
        this->AIcon::update();
        return (PA::Object::Menu::AIcon::Action::NONE);
    }

}