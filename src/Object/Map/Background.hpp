#ifndef __OBJECT_BACKGROUND_HPP__
    #define __OBJECT_BACKGROUND_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Image.hpp"
    #include <unordered_map>
    #include <memory>

    #define CREATE_IMAGE std::make_shared<KA::Lib::SDL2::Image>( \
        "res/sprites/game/floor.png", \
        KA::Vector2i{30, 30}, KA::Vector2i{0, 0}, \
        true, KA::Vector2i{1, 1} \
    )

class KA::Object::Background {

    private:
    KA::Vector2i dim = {100, 100};
    std::unordered_map<std::string, std::shared_ptr<KA::Lib::SDL2::Image>> images;
    std::unordered_map<std::string, KA::Vector2i> spriteIndex;
    std::unordered_map<int, std::unordered_map<int, std::shared_ptr<KA::Lib::SDL2::Image>>> sprites;

    public:
    Background();
    void draw();

};

#endif