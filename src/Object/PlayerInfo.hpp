#ifndef __OBJECT_PLAYER_INFO_HPP__
    #define __OBJECT_PLAYER_INFO_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Global/Error/NotEnoughMoney.hpp"
    #include <memory>

class PA::Object::PlayerInfo {

    private:
    int money = 2000;
    int income = 200;
    int incomeTimer = 12;

    public:
    PlayerInfo() {};
    PlayerInfo(const PlayerInfo &) = delete;
    PlayerInfo &operator=(const PlayerInfo &) = delete;
    int getMoney();
    void setMoney(int money);
    void addMoney(int money);
    static std::shared_ptr<PlayerInfo> getInstance();
    int getIncome() const;
    int getIncomeTimer() const;

};

#endif