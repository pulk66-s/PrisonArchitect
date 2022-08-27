#include "ATile.hpp"

namespace PA::Object::Tile {

    bool ATile::isColliding() {
        return (this->colliding);
    }

    void ATile::draw() {
        if (this->spriteSheet != nullptr) {
            this->spriteSheet->draw();
        }
    }

    std::string ATile::getName() {
        return (this->name);
    }

    void ATile::setWallPosition(WallPosition position) {
        this->spriteSheet->setIndex(this->wallPositions[position]);
    }

    void ATile::setColliding(bool colliding) {
        this->colliding = colliding;
    }

    void ATile::setPos(PA::Vector2i position) {
        this->spriteSheet->setPos(position);
    }

    PA::Vector2i ATile::getPos() const {
        return (this->spriteSheet->getPos());
    }

    void ATile::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->spriteSheet->setStatus(status);
    }

    bool ATile::operator<(const ATile& other) const {
        return (this->getPos() < other.getPos());
    }

    PA::Vector2i ATile::getWallPosition(WallPosition position) {
        return (this->wallPositions[position]);
    }

}