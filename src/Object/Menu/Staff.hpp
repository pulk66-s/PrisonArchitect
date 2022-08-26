#ifndef __OBJECT_MENU_STAFF_HPP__
    #define __OBJECT_MENU_STAFF_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/AIcon.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"

class PA::Object::Menu::Staff : public PA::Object::Menu::AIcon {

    public:
    Staff();
    PA::Object::Menu::AIcon::Action update();

};

#endif