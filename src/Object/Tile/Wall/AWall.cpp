#include "Object/Tile/Wall/AWall.hpp"

namespace PA::Object::Tile::Wall {

    AWall::AWall() {
    }

    AWall::AWall(AWall *other) {
        this->spriteSheet = other->spriteSheet;
        this->wallPositions = other->wallPositions;
    }

    void AWall::setWallPosition(WallPosition position) {
        this->spriteSheet->setIndex(this->wallPositions[position]);
    }

    void AWall::setPos(PA::Vector2i position) {
        this->spriteSheet->setPos(position);
    }

    PA::Vector2i AWall::getPos() const {
        return (this->spriteSheet->getPos());
    }

    void AWall::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->spriteSheet->setStatus(status);
    }

    bool AWall::operator<(const AWall& other) const {
        return (this->getPos() < other.getPos());
    }

    PA::Vector2i AWall::getWallPosition(WallPosition position) {
        return (this->wallPositions[position]);
    }

    void AWall::draw() {
        if (this->spriteSheet != nullptr) {
            this->spriteSheet->draw();
        }
    }

    void AWall::update() {
    }

}