#include "Object/Menu/PlayerMoneyIncome.hpp"

namespace PA::Object::Menu::Player {

    PlayerMoneyIncome::PlayerMoneyIncome() {
        std::string incomeText = std::to_string(this->playerInfo->getIncome()) + "$";
        this->playerMoneyIncomeText = std::make_unique<PA::Lib::SDL2::Graphic::Text>(
            incomeText, PA::Vector2i{630, 10}, PA::Vector2i{100, 50},
            PA::Lib::SDL2::Camera::Status::FIXED,
            SDL_Color{0, 255, 0, 255}
        );
        this->playerMoneyIncomeRectangle = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2i{620, 0}, PA::Vector2i{120, 70},
            SDL_Color{0, 0, 0, 100}, true,
            PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    void PlayerMoneyIncome::update() {
        double now = std::clock();
        if (now - this->lastUpdate > this->playerInfo->getIncomeTimer() * CLOCKS_PER_SEC) {
            this->playerInfo->addMoney(this->playerInfo->getIncome());
            this->lastUpdate = now;
        }
    }

    void PlayerMoneyIncome::draw() {
        this->playerMoneyIncomeRectangle->draw();
        this->playerMoneyIncomeText->draw();
    }

}