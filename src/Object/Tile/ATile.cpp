#include "ATile.hpp"

namespace PA::Object::Tile {

    ATile::ATile() {
        this->grid = PA::Object::Map::Grid::getInstance();
    }

    ATile::~ATile() {
    }

    bool ATile::isColliding() {
        return (this->colliding);
    }

    void ATile::draw() {
        if (this->image != nullptr) {
            this->image->draw();
        }
    }

    std::string ATile::getName() {
        return (this->name);
    }

    void ATile::setWallPosition(WallPosition position) {
        this->image->setIndex(this->wallPositions[position]);
    }

}