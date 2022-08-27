#ifndef __PA_OBJECT_MENU_NOTIF_SUCCESS_HPP__
    #define __PA_OBJECT_MENU_NOTIF_SUCCESS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/Notif/ANotif.hpp"

class PA::Object::Menu::Notif::Success : public PA::Object::Menu::Notif::ANotif {

    public:
    Success(std::string message, PA::Vector2i pos, PA::Vector2i dim);

};

#endif