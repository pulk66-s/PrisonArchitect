#ifndef __PA_OBJECT_MENU_ERROR_HPP__
    #define __PA_OBJECT_MENU_ERROR_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <string>
    #include <memory>

class PA::Object::Menu::Error {

    private:
    std::string message = "";
    std::unique_ptr<PA::Lib::SDL2::Graphic::Text> text;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> background;
    bool _isDone = false;

    public:
    Error(std::string message, PA::Vector2i pos, PA::Vector2i dim);
    void draw();
    void update();
    bool isDone() const;
    void setPos(PA::Vector2i pos);

};

#endif