#include "ATile.hpp"

namespace PA::Object::Tile {

    bool ATile::isColliding() {
        return (this->colliding);
    }

    std::string ATile::getName() const {
        return (this->name);
    }

    void ATile::setColliding(bool colliding) {
        this->colliding = colliding;
    }

    int ATile::getPrice() const {
        return (this->price);
    }

}