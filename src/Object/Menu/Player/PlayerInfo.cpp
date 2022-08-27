#include "PlayerInfo.hpp"

namespace PA::Object::Menu::Player {

    void PlayerInfo::draw() {
        this->playerMoney.draw();
        this->playerMoneyIncome.draw();
    }

    void PlayerInfo::update() {
        this->playerMoney.update();
        this->playerMoneyIncome.update();
    }

}