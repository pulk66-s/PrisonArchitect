#include "PlayerInfo.hpp"

namespace PA::Object::Menu {

    PlayerInfo::PlayerInfo()
    {
        this->playerInfo = PA::Object::PlayerInfo::getInstance();
        std::string text = std::to_string(this->playerInfo->getMoney()) + "€";
        this->playerMoneyText = std::make_unique(
            text, PA::Vector2i{0, 0}, PA::Vector2i{100, 100},
            PA::Lib::SDL2::Camera::Status::FIXED,
            SDL_Color{0, 0, 0, 255}
        );
    }

    void PlayerInfo::draw() {
        this->playerMoneyText->draw();
    }

    void PlayerInfo::update() {
        std::string text = std::to_string(this->playerInfo->getMoney()) + "€";
        if (text != this->playerMoneyText->getText()) {
            this->playerMoneyText->setText(text);
        }
    }

}