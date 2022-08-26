#ifndef __OBJECT_MENU_PLAYER_INFO_HPP__
    #define __OBJECT_MENU_PLAYER_INFO_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include <memory>

class PA::Object::Menu::PlayerInfo {

    private:
    std::shared_ptr<PA::Object::PlayerInfo> playerInfo;
    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> playerMoneyText;

    public:
    PlayerInfo();
    void draw();
    void update();

};

#endif