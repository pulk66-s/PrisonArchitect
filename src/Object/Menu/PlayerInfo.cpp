#include "PlayerInfo.hpp"

namespace PA::Object::Menu {

    void PlayerInfo::draw() {
        this->playerMoney.draw();
        this->playerMoneyIncome.draw();
    }

    void PlayerInfo::update() {
        this->playerMoney.update();
        this->playerMoneyIncome.update();
    }

}