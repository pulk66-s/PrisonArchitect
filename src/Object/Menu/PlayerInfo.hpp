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

class PA::Object::Menu::PlayerInfo {

    private:
    PA::Object::Menu::PlayerMoney playerMoney;
    PA::Object::Menu::PlayerMoneyIncome playerMoneyIncome;

    public:
    void draw();
    void update();

};

#endif