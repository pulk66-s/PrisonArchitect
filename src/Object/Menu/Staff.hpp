#ifndef __OBJECT_MENU_STAFF_HPP__
    #define __OBJECT_MENU_STAFF_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/AIcon.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"

class KA::Object::Menu::Staff : public KA::Object::Menu::AIcon {

    public:
    Staff();
    KA::Object::Menu::AIcon::Action update();

};

#endif