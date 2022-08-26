#ifndef __OBJECT_BACKGROUND_HPP__
    #define __OBJECT_BACKGROUND_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Image.hpp"
    #include <unordered_map>
    #include <memory>

    #define CREATE_IMAGE std::make_shared<PA::Lib::SDL2::Graphic::Image>( \
        "res/sprites/game/floor.png", \
        PA::Vector2i{30, 30}, PA::Vector2i{0, 0}, \
        true, PA::Vector2i{1, 1} \
    )

class PA::Object::Background {

    private:
    PA::Vector2i dim = {100, 100};
    std::unordered_map<std::string, std::shared_ptr<PA::Lib::SDL2::Graphic::Image>> images;
    std::unordered_map<std::string, PA::Vector2i> spriteIndex;
    std::unordered_map<int, std::unordered_map<int, std::shared_ptr<PA::Lib::SDL2::Graphic::Image>>> sprites;

    public:
    Background();
    void draw();

};

#endif