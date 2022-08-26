#include "Ia.hpp"

namespace KA::Object::PNJ::IA {

    Ia::Ia()
    {
        this->grid = KA::Object::Grid::getInstance();
        this->tileManager = KA::Object::TileManager::getInstance();
    }

    void Ia::update(KA::Vector2i pos)
    {
        KA::Vector2i transformedPos = this->grid->transformPos(pos);
        KA::Vector2i gridDim = this->grid->getDim();
        std::unordered_map<KA::Object::PNJ::IA::Ia::Move, KA::Vector2i> buff = {
            {KA::Object::PNJ::IA::Ia::Move::UP, KA::Vector2i{0, -1 * gridDim.y}},
            {KA::Object::PNJ::IA::Ia::Move::DOWN, KA::Vector2i{0, 2 * gridDim.y}},
            {KA::Object::PNJ::IA::Ia::Move::LEFT, KA::Vector2i{-1 * gridDim.x, 0}},
            {KA::Object::PNJ::IA::Ia::Move::RIGHT, KA::Vector2i{2 * gridDim.x, 0}},
            {KA::Object::PNJ::IA::Ia::Move::NONE, KA::Vector2i{0, 0}},
        };
        bool goodDir = false;
        int max_loop = 10, loop = 0;
        while (!goodDir && loop < max_loop) {
            loop++;
            int rand = std::rand() % 5;
            this->nextMove = static_cast<KA::Object::PNJ::IA::Ia::Move>(rand);
            KA::Vector2i nextPos = transformedPos + buff[nextMove];
            std::shared_ptr<KA::Object::Tile::ITile> tile = this->tileManager->getTile(nextPos);
            if (tile == nullptr || !tile->isColliding()) {
                goodDir = true;
                return;
            }
        }
        this->nextMove = KA::Object::PNJ::IA::Ia::Move::NONE;
    }

    Ia::Move Ia::getMove()
    {
        Move move = this->nextMove;
        this->nextMove = NONE;
        return (move);
    }

}