#ifndef __PA_OBJECT_MENU_NOTIF_ANOTIF_HPP__
    #define __PA_OBJECT_MENU_NOTIF_ANOTIF_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include <string>
    #include <memory>

class PA::Object::Menu::Notif::ANotif {

    protected:
    std::string message = "";
    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> text;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> background;
    bool _isDone = false;

    public:
    ANotif(std::string message, PA::Vector2i pos, PA::Vector2i dim);
    void draw();
    void update();
    bool isDone() const;
    void setPos(PA::Vector2i pos);

};

#endif