#include "Ia.hpp"

namespace PA::Object::PNJ::IA {

    void Ia::update()
    {
        PA::Vector2<int> gridDim = this->grid->getSquareDim();
        std::unordered_map<PA::Object::PNJ::IA::Ia::Move, PA::Vector2<int>> buff = {
            {PA::Object::PNJ::IA::Ia::Move::UP, PA::Vector2<int>{0, -1 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::DOWN, PA::Vector2<int>{0, 1 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::LEFT, PA::Vector2<int>{-1 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::RIGHT, PA::Vector2<int>{1 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::NONE, PA::Vector2<int>{0, 0}},
        };
        int randNb = rand() % 5;
        this->nextMove = static_cast<PA::Object::PNJ::IA::Ia::Move>(randNb);
    }

    Ia::Move Ia::getMove()
    {
        Move move = this->nextMove;
        this->nextMove = NONE;
        return (move);
    }

}