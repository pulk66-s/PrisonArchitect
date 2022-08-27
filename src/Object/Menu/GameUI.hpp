#ifndef __OBJECT_MENU_GAMEUI_HPP__
    #define __OBJECT_MENU_GAMEUI_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/Room.hpp"
    #include "Object/Menu/Staff.hpp"
    #include "Object/Menu/Material.hpp"
    #include "Object/Menu/PlayerInfo.hpp"
    #include "Object/Menu/Errors.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"
    #include <memory>
    #include <unordered_map>
    #include <vector>

class PA::Object::Menu::GameUI {

    private:
    PA::Object::Menu::Room roomIcon;
    PA::Object::Menu::Staff staffIcon;
    PA::Object::Menu::Material materialIcon;
    PA::Object::Menu::PlayerInfo playerInfo;
    PA::Object::Menu::Errors errors;

    public:
    void draw();
    PA::Object::Menu::AIcon::Action update();
    void addError(std::string message);

};

#endif