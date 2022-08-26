#ifndef __OBJECT_PNJ_PNJ_HPP__
    #define __OBJECT_PNJ_PNJ_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Lib/SDL2/Image.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/BadInstance.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "IA/Workman.hpp"
    #include <string>
    #include <memory>
    #include <unordered_map>

class KA::Object::PNJ::Pnj {
    protected:
    KA::Lib::SDL2::Image spriteSheet;
    unsigned short nb_variant, curr_variant = 0;
    KA::Vector2i spriteIndex;
    KA::Vector2i pos;
    std::unordered_map<KA::Object::PNJ::IA::Ia::Move, KA::Vector2i> moveDirection;
    std::unordered_map<KA::Object::PNJ::IA::Ia::Move, int> moveSpriteSheetIndex;

    // IA
    std::unique_ptr<KA::Object::PNJ::IA::Ia> ia = nullptr;
    unsigned int lastUpdateTime = SDL_GetTicks();
    float moveTimeOffset = 0.1; // seconds
    KA::Vector2i speed = {1, 1};
    KA::Object::PNJ::IA::Ia::Move currMove = KA::Object::PNJ::IA::Ia::Move::NONE;
    int moveOffset = 0;
    int maxMoveOffset = 10;

    public:
    Pnj(std::string path, KA::Vector2i pos={0, 0}, unsigned short variant=1);
    bool draw();
    void update();

};

#endif
