#ifndef __OBJECT_MENU_PLAYER_INFO_HPP__
    #define __OBJECT_MENU_PLAYER_INFO_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Object/Menu/PlayerMoney.hpp"
    #include "Object/Menu/PlayerMoneyIncome.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <memory>
    #include <ctime>

class PA::Object::Menu::Player::PlayerInfo {

    private:
    PA::Object::Menu::Player::PlayerMoney playerMoney;
    PA::Object::Menu::Player::PlayerMoneyIncome playerMoneyIncome;

    public:
    void draw();
    void update();

};

#endif