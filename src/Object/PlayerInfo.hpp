#ifndef __OBJECT_PLAYER_INFO_HPP__
    #define __OBJECT_PLAYER_INFO_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include <memory>

class PA::Object::PlayerInfo {

    private:
    int money = 2000;

    public:
    PlayerInfo() {};
    PlayerInfo(const PlayerInfo &) = delete;
    PlayerInfo &operator=(const PlayerInfo &) = delete;
    int getMoney();
    void setMoney(int money);
    void addMoney(int money);
    std::shared_ptr<PlayerInfo> getInstance();

};

#endif