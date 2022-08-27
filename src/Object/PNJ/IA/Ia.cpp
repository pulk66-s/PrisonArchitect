#include "Ia.hpp"

namespace PA::Object::PNJ::IA {

    void Ia::update(PA::Vector2i pos)
    {
        PA::Vector2i gridDim = this->grid->getSquareDim();
        std::unordered_map<PA::Object::PNJ::IA::Ia::Move, PA::Vector2i> buff = {
            {PA::Object::PNJ::IA::Ia::Move::UP, PA::Vector2i{0, -1 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::DOWN, PA::Vector2i{0, 1 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::LEFT, PA::Vector2i{-1 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::RIGHT, PA::Vector2i{1 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::NONE, PA::Vector2i{0, 0}},
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