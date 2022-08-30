#include "Workman.hpp"

namespace PA::Object::PNJ {

    Workman::Workman(PA::Vector2<int> pos)
    : Pnj("res/sprites/pnj/workman.png", pos, 4)
    {
        this->ia = std::make_unique<PA::Object::PNJ::IA::Workman>();
    }

    Workman::~Workman()
    {
    }

}