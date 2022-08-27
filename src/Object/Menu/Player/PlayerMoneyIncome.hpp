#ifndef __PA_OBJECT_MENU_PLAYER_MONEY_INCOME_HPP__
    #define __PA_OBJECT_MENU_PLAYER_MONEY_INCOME_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Global/Error/NotifSuccess.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <memory>
    #include <ctime>

class PA::Object::Menu::Player::PlayerMoneyIncome {

    private:
    std::shared_ptr<PA::Object::PlayerInfo> playerInfo = PA::Object::PlayerInfo::getInstance();

    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> playerMoneyIncomeText;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> playerMoneyIncomeRectangle;
    double lastUpdate = std::clock();

    public:
    PlayerMoneyIncome();
    void update();
    void draw();

};

#endif