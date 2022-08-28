#include "Pnj.hpp"

namespace PA::Object::PNJ {

    Pnj::Pnj(std::string path, PA::Vector2<int> pos, unsigned short variant)
    {
        this->pos = pos;
        this->nb_variant = variant;
        this->spriteSheet = std::make_unique<PA::Lib::SDL2::Graphic::SpriteSheet>(
            path, PA::Vector2<int>{4, 4}, PA::Vector2<int>{0, 0}, this->grid->getSquareDim()
        );
        if (variant > 1) {
            this->curr_variant = std::rand() % variant;
            this->spriteSheet->setIndex({0, this->curr_variant});
        }
        this->moveDirection = {
            {IA::Ia::Move::NONE, {0, 0}},
            {IA::Ia::Move::UP, {0, -this->speed.y}},
            {IA::Ia::Move::DOWN, {0, this->speed.y}},
            {IA::Ia::Move::LEFT, {-this->speed.x, 0}},
            {IA::Ia::Move::RIGHT, {this->speed.x, 0}}
        };
        this->moveSpriteSheetIndex = {
            {IA::Ia::Move::NONE, 0},
            {IA::Ia::Move::UP, 1},
            {IA::Ia::Move::DOWN, 0},
            {IA::Ia::Move::LEFT, 2},
            {IA::Ia::Move::RIGHT, 3}
        };
    }

    void Pnj::draw()
    {
        this->spriteSheet->draw();
    }

    void Pnj::update()
    {
        if (this->ia == nullptr)
            return;
        this->ia->update();
        unsigned int currentTime = SDL_GetTicks();
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        if (currentTime > this->lastUpdateTime + 1000 * this->moveTimeOffset) {
            this->lastUpdateTime = currentTime;
            if (this->moveOffset <= 0) {
                this->currMove = this->ia->getMove();
                this->moveOffset = this->maxMoveOffset;
            }
            PA::Vector2<int> moveBuff = this->moveDirection[this->currMove];
            PA::Vector2<int> nextPos = this->grid->transformPos(this->pos + moveBuff);
            if (this->currMove == IA::Ia::Move::RIGHT) {
                nextPos.x += squareDim.x;
            }
            if (this->currMove == IA::Ia::Move::DOWN) {
                nextPos.y += squareDim.y;
            }
            std::shared_ptr<PA::Object::Tile::ITile> tile = this->tileManager->getTile(nextPos);
            if (tile == nullptr) {
                this->pos += moveBuff;
                this->spriteSheet->setPos(this->pos);
                this->spriteSheet->setIndex({this->moveSpriteSheetIndex[this->currMove], this->curr_variant});
            }
            this->moveOffset--;
        }
    }

}
