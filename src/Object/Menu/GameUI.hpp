#ifndef __OBJECT_MENU_GAMEUI_HPP__
    #define __OBJECT_MENU_GAMEUI_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/Room.hpp"
    #include "Object/Menu/Staff.hpp"
    #include "Object/Menu/Material.hpp"
    #include "Object/Menu/PlayerInfo.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"
    #include <memory>
    #include <unordered_map>
    #include <vector>

class KA::Object::Menu::GameUI {

    private:
    KA::Object::Menu::Room roomIcon;
    KA::Object::Menu::Staff staffIcon;
    KA::Object::Menu::Material materialIcon;
    // KA::Object::Menu::PlayerInfo playerInfo;

    public:
    void draw();
    KA::Object::Menu::AIcon::Action update();

};

#endif