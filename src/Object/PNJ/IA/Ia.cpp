#include "Ia.hpp"

namespace PA::Object::PNJ::IA {

    Ia::Ia()
    {
        this->grid = PA::Object::Map::Grid::getInstance();
        this->tileManager = PA::Object::Tile::TileManager::getInstance();
    }

    void Ia::update(PA::Vector2i pos)
    {
        PA::Vector2i transformedPos = this->grid->transformPos(pos);
        PA::Vector2i gridDim = this->grid->getDim();
        std::unordered_map<PA::Object::PNJ::IA::Ia::Move, PA::Vector2i> buff = {
            {PA::Object::PNJ::IA::Ia::Move::UP, PA::Vector2i{0, -1 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::DOWN, PA::Vector2i{0, 2 * gridDim.y}},
            {PA::Object::PNJ::IA::Ia::Move::LEFT, PA::Vector2i{-1 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::RIGHT, PA::Vector2i{2 * gridDim.x, 0}},
            {PA::Object::PNJ::IA::Ia::Move::NONE, PA::Vector2i{0, 0}},
        };
        bool goodDir = false;
        int max_loop = 10, loop = 0;
        while (!goodDir && loop < max_loop) {
            loop++;
            int rand = std::rand() % 5;
            this->nextMove = static_cast<PA::Object::PNJ::IA::Ia::Move>(rand);
            PA::Vector2i nextPos = transformedPos + buff[nextMove];
            std::shared_ptr<PA::Object::Tile::ITile> tile = this->tileManager->getTile(nextPos);
            if (tile == nullptr || !tile->isColliding()) {
                goodDir = true;
                return;
            }
        }
        this->nextMove = PA::Object::PNJ::IA::Ia::Move::NONE;
    }

    Ia::Move Ia::getMove()
    {
        Move move = this->nextMove;
        this->nextMove = NONE;
        return (move);
    }

}