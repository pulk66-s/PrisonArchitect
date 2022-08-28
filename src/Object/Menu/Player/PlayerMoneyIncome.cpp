#include "Object/Menu/Player/PlayerMoneyIncome.hpp"

namespace PA::Object::Menu::Player {

    PlayerMoneyIncome::PlayerMoneyIncome() {
        std::string incomeText = std::to_string(this->playerInfo->getIncome()) + "$";
        this->playerMoneyIncomeText = std::make_unique<PA::Lib::SDL2::Graphic::Text>(
            incomeText, PA::Vector2<int>{630, 10}, PA::Vector2<int>{100, 50},
            PA::Lib::SDL2::Camera::Status::FIXED,
            SDL_Color{0, 255, 0, 255}
        );
        this->playerMoneyIncomeRectangle = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2<int>{620, 0}, PA::Vector2<int>{120, 70},
            SDL_Color{0, 0, 0, 100}, true,
            PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    void PlayerMoneyIncome::update() {
        double now = std::clock();
        if (now - this->lastUpdate > this->playerInfo->getIncomeTimer() * CLOCKS_PER_SEC) {
            this->playerInfo->addMoney(this->playerInfo->getIncome());
            this->lastUpdate = now;
            throw PA::Error::NotifSuccess("You have earned " + std::to_string(this->playerInfo->getIncome()) + "$", __FILE__);
        }
    }

    void PlayerMoneyIncome::draw() {
        this->playerMoneyIncomeRectangle->draw();
        this->playerMoneyIncomeText->draw();
    }

}