#include "Object/Tile/Wall/AWall.hpp"

namespace PA::Object::Tile::Wall {

    AWall::AWall() {
    }

    AWall::AWall(AWall *other) {
        this->spriteSheet = other->spriteSheet;
        this->wallPositions = other->wallPositions;
        this->price = other->price;
        this->name = other->name;
        this->item = other->item;
    }

    void AWall::setWallPosition(WallPosition position) {
        this->spriteSheet->setIndex(this->wallPositions[position]);
    }

    void AWall::setPos(PA::Vector2<int> position) {
        this->spriteSheet->setPos(position);
    }

    PA::Vector2<int> AWall::getPos() const {
        return (this->spriteSheet->getPos());
    }

    void AWall::setStatus(PA::Lib::SDL2::Camera::Status status) {
        this->spriteSheet->setStatus(status);
    }

    bool AWall::operator<(const AWall& other) const {
        return (this->getPos() < other.getPos());
    }

    PA::Vector2<int> AWall::getWallPosition(WallPosition position) {
        return (this->wallPositions[position]);
    }

    void AWall::draw() {
        if (this->spriteSheet != nullptr) {
            this->spriteSheet->draw();
        }
    }

    void AWall::update() {
    }

    void AWall::createSpriteSheet(PA::Vector2<int> pos, PA::Vector2<int> index) {
        PA::Vector2<int> gridDim = this->grid->getSquareDim();
        this->spriteSheet = std::make_shared<PA::Lib::SDL2::Graphic::SpriteSheet>(
            "res/sprites/game/walls.png", PA::Vector2<int>(32, 32),
            pos, gridDim
        );
        this->spriteSheet->setIndex(index);
    }

    std::string AWall::getItem() {
        return (this->item);
    }

}