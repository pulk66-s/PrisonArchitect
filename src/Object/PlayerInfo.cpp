#include "PlayerInfo.hpp"

namespace KA::Object {

    std::shared_ptr<PlayerInfo> PlayerInfo::getInstance() {
        static std::shared_ptr<PlayerInfo> instance = std::make_shared<PlayerInfo>();
        return (instance);
    }

    int PlayerInfo::getMoney() {
        return (this->money);
    }

    void PlayerInfo::setMoney(int money) {
        this->money = money;
    }

    void PlayerInfo::addMoney(int money) {
        this->money += money;
    }

}