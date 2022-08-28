#include "Object/Menu/Player/PlayerMoney.hpp"

namespace PA::Object::Menu::Player {

    PlayerMoney::PlayerMoney() {
        std::string text = std::to_string(this->playerInfo->getMoney()) + "$";
        this->playerMoneyText = std::make_unique<PA::Lib::SDL2::Graphic::Text>(
            text, PA::Vector2<int>{500, 10}, PA::Vector2<int>{100, 50},
            PA::Lib::SDL2::Camera::Status::FIXED,
            SDL_Color{255, 255, 255, 255}
        );
        this->playerMoneyRectangle = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2<int>{490, 0}, PA::Vector2<int>{120, 70},
            SDL_Color{0, 0, 0, 100}, true,
            PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    void PlayerMoney::draw() {
        this->playerMoneyRectangle->draw();
        this->playerMoneyText->draw();
    }

    void PlayerMoney::update() {
        std::string text = std::to_string(this->playerInfo->getMoney()) + "$";
        if (text != this->playerMoneyText->getText()) {
            this->playerMoneyText->setText(text);
        }
    }

}
