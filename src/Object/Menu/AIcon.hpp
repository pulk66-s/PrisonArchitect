#ifndef __OBJECT_MENU_AICON_HPP__
    #define __OBJECT_MENU_AICON_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Image.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <memory>
    #include <unordered_map>

    #define CREATE_ICON(name, x, y, w, h) Icon{std::make_shared<PA::Lib::SDL2::Graphic::Image>( \
        this->spritesheetPath, \
        PA::Vector2i{w, h}, PA::Vector2i{x, y}, \
        true, this->spriteSheetDim, PA::Lib::SDL2::Camera::Status::FIXED \
    ), std::make_shared<PA::Lib::SDL2::Graphic::Text>(name, PA::Vector2i{x, y + w}, PA::Vector2i{w, 14}, PA::Lib::SDL2::Camera::Status::FIXED)}

class PA::Object::Menu::AIcon {

    protected:
    typedef struct Icon_s {
        std::shared_ptr<PA::Lib::SDL2::Graphic::Image> icon;
        std::shared_ptr<PA::Lib::SDL2::Graphic::Text> text;
    } Icon;
    std::string spritesheetPath;
    PA::Vector2i pos, dim, spriteSheetDim = {1, 1};
    SDL_Color menuBackgroundColor = {0, 0, 0, 0};
    std::unique_ptr<PA::Lib::SDL2::Graphic::Image> roomImage;
    bool displayed = false;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> menuBackground;
    std::unordered_map<std::string, Icon> roomIcons;

    public:
    typedef enum Action_e {
        DELIVERIES,
        WORKMAN,
        BRICK_WALL,
        NONE
    } Action;
    AIcon(PA::Vector2i pos, PA::Vector2i dim, PA::Vector2i index, std::string spritesheetPath);
    PA::Object::Menu::AIcon::Action update();
    void draw();
    bool isDisplayed();

};

#endif