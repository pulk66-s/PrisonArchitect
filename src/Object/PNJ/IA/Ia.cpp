#include "Ia.hpp"

namespace PA::Object::PNJ::IA {

    Ia::Ia() {
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

    void Ia::idle(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant) {
        unsigned int currentTime = SDL_GetTicks();
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        if (currentTime > this->lastUpdateTime + 1000 * this->moveTimeOffset) {
            this->lastUpdateTime = currentTime;
            if (this->moveOffset <= 0) {
                this->currMove = this->getMove();
                this->moveOffset = this->maxMoveOffset;
            }
            PA::Vector2<int> moveBuff = this->moveDirection[this->currMove];
            PA::Vector2<int> nextPos = this->grid->transformPos(*pos + moveBuff);
            if (this->currMove == IA::Ia::Move::RIGHT) {
                nextPos.x += squareDim.x;
            }
            if (this->currMove == IA::Ia::Move::DOWN) {
                nextPos.y += squareDim.y;
            }
            *pos += moveBuff;
            spriteSheet->setPos(*pos);
            spriteSheet->setIndex({this->moveSpriteSheetIndex[this->currMove], currVariant});
            this->moveOffset--;
        }
    }

    void Ia::moveToGoTo(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant) {
        PA::Vector2<int> move = {0, 0};
        if (this->goToPos->x > pos->x) {
            move.x = this->speed.x;
        } else if (this->goToPos->x < pos->x) {
            move.x = -this->speed.x;
        } else if (this->goToPos->y > pos->y) {
            move.y = this->speed.y;
        } else if (this->goToPos->y < pos->y) {
            move.y = -this->speed.y;
        }
        *pos += move;
        spriteSheet->setPos(*pos);
        spriteSheet->setIndex({this->moveSpriteSheetIndex[this->currMove], currVariant});
    }

    void Ia::update(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant)
    {
        if (this->goToPos == nullptr) {
            this->idle(pos, spriteSheet, currVariant);
        } else {
            this->moveToGoTo(pos, spriteSheet, currVariant);
        }
    }

    Ia::Move Ia::getMove()
    {
        int randNb = rand() % 5;
        return (static_cast<PA::Object::PNJ::IA::Ia::Move>(randNb));
    }

    void Ia::setGoToPos(PA::Vector2<int> pos)
    {
        this->goToPos = std::make_shared<PA::Vector2<int>>(pos);
    }

    void Ia::setGoToPos(std::shared_ptr<PA::Vector2<int>> pos)
    {
        this->goToPos = pos;
    }

    PA::Vector2<int> Ia::getGoToPos()
    {
        if (this->goToPos == nullptr) {
            throw PA::Error::NullPtr("goToPos is nullptr", __FILE__);
        }
        return (*this->goToPos);
    }

}