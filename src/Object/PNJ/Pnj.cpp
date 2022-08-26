#include "Pnj.hpp"

namespace KA::Object::PNJ {

    Pnj::Pnj(std::string path, KA::Vector2i pos, unsigned short variant)
    : spriteSheet(path, {50, 50}, pos, true, {4, 4})
    {
        this->pos = pos;
        this->nb_variant = variant;
        if (variant > 1) {
            this->curr_variant = std::rand() % variant;
            this->spriteSheet.setIndex({0, this->curr_variant});
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

    bool Pnj::draw()
    {
        return this->spriteSheet.draw();
    }

    void Pnj::update()
    {
        if (this->ia == nullptr)
            return;
        this->ia->update(this->pos);
        unsigned int currentTime = SDL_GetTicks();
        if (currentTime > this->lastUpdateTime + 1000 * this->moveTimeOffset) {
            this->lastUpdateTime = currentTime;
            if (this->moveOffset <= 0) {
                this->currMove = this->ia->getMove();
                this->moveOffset = this->maxMoveOffset;
            }
            KA::Vector2i moveBuff = this->moveDirection[this->currMove];
            this->pos += moveBuff;
            this->spriteSheet.setPosition(this->pos);
            this->spriteSheet.setIndex({this->moveSpriteSheetIndex[this->currMove], this->curr_variant});
            this->moveOffset--;
        }
    }

}
