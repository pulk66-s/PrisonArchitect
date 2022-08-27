#include "GameUI.hpp"

namespace PA::Object::Menu {

    void GameUI::draw() {
        this->roomIcon.draw();
        this->staffIcon.draw();
        this->materialIcon.draw();
        this->playerInfo.draw();
        this->errors.draw();
    }

    PA::Object::Menu::AIcon::Action GameUI::update() {
        this->playerInfo.update();
        this->errors.update();
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

    void GameUI::addError(std::string message) {
        this->errors.addError(message);
    }

}
