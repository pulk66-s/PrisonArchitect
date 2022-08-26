#include "GameUI.hpp"

namespace PA::Object::Menu {

    void GameUI::draw() {
        this->roomIcon.draw();
        this->staffIcon.draw();
        this->materialIcon.draw();
        // this->playerInfo.draw();
    }

    PA::Object::Menu::AIcon::Action GameUI::update() {
        // this->playerInfo.update();
        PA::Object::Menu::AIcon::Action roomAction = this->roomIcon.update();
        if (roomAction != PA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        roomAction = this->staffIcon.update();
        if (roomAction != PA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        roomAction = this->materialIcon.update();
        if (roomAction != PA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        return (PA::Object::Menu::AIcon::Action::NONE);
    }

}
