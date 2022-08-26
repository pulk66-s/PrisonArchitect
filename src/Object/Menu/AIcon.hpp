#ifndef __OBJECT_MENU_AICON_HPP__
    #define __OBJECT_MENU_AICON_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Image.hpp"
    #include "Lib/SDL2/Text.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <memory>
    #include <unordered_map>

    #define CREATE_ICON(name, x, y, w, h) Icon{std::make_shared<KA::Lib::SDL2::Image>( \
        this->spritesheetPath, \
        KA::Vector2i{w, h}, KA::Vector2i{x, y}, \
        true, this->spriteSheetDim, KA::Lib::SDL2::Camera::Status::FIXED \
    ), std::make_shared<KA::Lib::SDL2::Text>(name, KA::Vector2i{x, y + w}, KA::Vector2i{w, 14}, KA::Lib::SDL2::Camera::Status::FIXED)}

class KA::Object::Menu::AIcon {

    protected:
    typedef struct Icon_s {
        std::shared_ptr<KA::Lib::SDL2::Image> icon;
        std::shared_ptr<KA::Lib::SDL2::Text> text;
    } Icon;
    std::string spritesheetPath;
    KA::Vector2i pos, dim, spriteSheetDim = {1, 1};
    SDL_Color menuBackgroundColor = {0, 0, 0, 0};
    std::unique_ptr<KA::Lib::SDL2::Image> roomImage;
    bool displayed = false;
    std::unique_ptr<KA::Lib::SDL2::Shape::Rectangle> menuBackground;
    std::unordered_map<std::string, Icon> roomIcons;

    public:
    typedef enum Action_e {
        DELIVERIES,
        WORKMAN,
        BRICK_WALL,
        NONE
    } Action;
    AIcon(KA::Vector2i pos, KA::Vector2i dim, KA::Vector2i index, std::string spritesheetPath);
    KA::Object::Menu::AIcon::Action update();
    void draw();
    bool isDisplayed();

};

#endif