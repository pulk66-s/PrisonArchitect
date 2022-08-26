#include "Room.hpp"

namespace PA::Object::Menu {

    Room::Room() 
    : AIcon({100, 840}, {64, 64}, {0, 0}, "res/sprites/menu/room_ui.png") {
        this->roomIcons["deliveries"] = CREATE_ICON("deliveries", 120, 620, 48, 48);
    }

    PA::Object::Menu::AIcon::Action Room::update() {
        if (this->displayed) {
            if (this->roomIcons["deliveries"].icon->isClick()) {
                this->displayed = false;
                return (PA::Object::Menu::AIcon::Action::DELIVERIES);
            }
        }
        this->AIcon::update();
        return (PA::Object::Menu::AIcon::Action::NONE);
    }

}