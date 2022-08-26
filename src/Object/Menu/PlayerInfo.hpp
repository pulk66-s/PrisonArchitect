#ifndef __OBJECT_MENU_PLAYER_INFO_HPP__
    #define __OBJECT_MENU_PLAYER_INFO_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Lib/SDL2/Text.hpp"
    #include <memory>

class KA::Object::Menu::PlayerInfo {

    private:
    std::shared_ptr<KA::Object::PlayerInfo> playerInfo;
    std::unique_ptr<KA::Lib::SDL2::Text> playerMoneyText;

    public:
    PlayerInfo();
    void draw();
    void update();

};

#endif