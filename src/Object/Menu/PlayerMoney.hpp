#ifndef __PA_OBJECT_MENU_PLAYER_MONEY_HPP__
    #define __PA_OBJECT_MENU_PLAYER_MONEY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <memory>
    #include <string>

class PA::Object::Menu::PlayerMoney {

    private:
    std::shared_ptr<PA::Object::PlayerInfo> playerInfo = PA::Object::PlayerInfo::getInstance();

    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> playerMoneyText;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> playerMoneyRectangle;

    public:
    PlayerMoney();
    void draw();
    void update();

};

#endif