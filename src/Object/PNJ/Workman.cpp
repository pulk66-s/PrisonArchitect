#include "Workman.hpp"

namespace KA::Object::PNJ {

    Workman::Workman(KA::Vector2i pos)
    : Pnj("res/sprites/pnj/workman.png", pos, 4)
    {
        this->ia = std::make_unique<KA::Object::PNJ::IA::Workman>();
        this->speed = {1, 1};
        this->moveTimeOffset = 0.01;
        this->maxMoveOffset = 30;
    }

}