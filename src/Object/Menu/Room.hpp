#ifndef __OBJECT_MENU_ROOM_HPP__
    #define __OBJECT_MENU_ROOM_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/AIcon.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class KA::Object::Menu::Room : public KA::Object::Menu::AIcon {

    public:
    Room();
    KA::Object::Menu::AIcon::Action update();
    using AIcon::draw;

};

#endif