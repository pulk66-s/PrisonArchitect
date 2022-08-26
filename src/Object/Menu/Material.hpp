#ifndef __OBJECT_MENU_MATERIAL_HPP__
    #define __OBJECT_MENU_MATERIAL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/AIcon.hpp"
    #include "Lib/SDL2/Renderer.hpp"

class PA::Object::Menu::Material : public PA::Object::Menu::AIcon {

    public:
    Material();
    PA::Object::Menu::AIcon::Action update();
    using AIcon::draw;

};

#endif