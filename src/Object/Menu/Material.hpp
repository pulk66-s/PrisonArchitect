#ifndef __OBJECT_MENU_MATERIAL_HPP__
    #define __OBJECT_MENU_MATERIAL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/AIcon.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class KA::Object::Menu::Material : public KA::Object::Menu::AIcon {

    public:
    Material();
    KA::Object::Menu::AIcon::Action update();
    using AIcon::draw;

};

#endif