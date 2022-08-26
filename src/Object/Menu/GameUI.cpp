#include "GameUI.hpp"

namespace KA::Object::Menu {

    void GameUI::draw() {
        this->roomIcon.draw();
        this->staffIcon.draw();
        this->materialIcon.draw();
        // this->playerInfo.draw();
    }

    KA::Object::Menu::AIcon::Action GameUI::update() {
        // this->playerInfo.update();
        KA::Object::Menu::AIcon::Action roomAction = this->roomIcon.update();
        if (roomAction != KA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        roomAction = this->staffIcon.update();
        if (roomAction != KA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        roomAction = this->materialIcon.update();
        if (roomAction != KA::Object::Menu::AIcon::Action::NONE) {
            return (roomAction);
        }
        return (KA::Object::Menu::AIcon::Action::NONE);
    }

}
