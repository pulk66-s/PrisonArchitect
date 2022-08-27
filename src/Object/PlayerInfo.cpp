#include "PlayerInfo.hpp"

namespace PA::Object {

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
        if (this->money + money < 0) {
            throw PA::Error::NotEnoughMoney("Not enough money " + std::to_string(money), __FILE__);
        }
        this->money += money;
    }

    int PlayerInfo::getIncome() const {
        return (this->income);
    }

    int PlayerInfo::getIncomeTimer() const {
        return (this->incomeTimer);
    }

}