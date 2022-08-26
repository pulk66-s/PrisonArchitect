#include "PlayerInfo.hpp"

namespace KA::Object::Menu {

    PlayerInfo::PlayerInfo()
    {
        this->playerInfo = KA::Object::PlayerInfo::getInstance();
        std::string text = std::to_string(this->playerInfo->getMoney()) + "€";
        this->playerMoneyText = std::make_unique(
            text, KA::Vector2i{0, 0}, KA::Vector2i{100, 100},
            KA::Lib::SDL2::Camera::Status::FIXED,
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