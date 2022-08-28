#ifndef __PA_OBJECT_MENU_ERROR_HPP__
    #define __PA_OBJECT_MENU_ERROR_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/Notif/ANotif.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <string>
    #include <memory>

class PA::Object::Menu::Notif::Error : public PA::Object::Menu::Notif::ANotif {

    public:
    Error(std::string message, PA::Vector2<int> pos, PA::Vector2<int> dim);
};

#endif