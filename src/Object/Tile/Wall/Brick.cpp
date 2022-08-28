#include "Object/Tile/Wall/Brick.hpp"

namespace PA::Object::Tile::Wall
{
    Brick::Brick(PA::Vector2i index, PA::Vector2i pos)
    {
        this->colliding = true;
        this->name = "brickWall";
        PA::Vector2i gridDim = this->grid->getSquareDim();
        this->spriteSheet = std::make_shared<PA::Lib::SDL2::Graphic::SpriteSheet>(
            "res/sprites/game/walls.png", PA::Vector2i(32, 32),
            pos, gridDim
        );
        this->spriteSheet->setIndex(index);
        this->wallPositions = {
            {Wall::AWall::WallPosition::CROSS, PA::Vector2i{14, 10}},
            {Wall::AWall::WallPosition::CORNER_UPPER_LEFT, PA::Vector2i{10, 8}},
            {Wall::AWall::WallPosition::CORNER_UPPER_RIGHT, PA::Vector2i{11, 8}},
            {Wall::AWall::WallPosition::CORNER_LOWER_LEFT, PA::Vector2i{10, 9}},
            {Wall::AWall::WallPosition::CORNER_LOWER_RIGHT, PA::Vector2i{11, 9}},
            {Wall::AWall::WallPosition::COLUMN, PA::Vector2i{8, 8}},
            {Wall::AWall::WallPosition::LINE, PA::Vector2i{9, 8}},
            {Wall::AWall::WallPosition::LEFT, PA::Vector2i{9, 9}},
            {Wall::AWall::WallPosition::RIGHT, PA::Vector2i{9, 10}},
            {Wall::AWall::WallPosition::UP, PA::Vector2i{8, 9}},
            {Wall::AWall::WallPosition::DOWN, PA::Vector2i{8, 10}},
            {Wall::AWall::WallPosition::TRI_DOWN, PA::Vector2i{12, 8}},
            {Wall::AWall::WallPosition::TRI_UP, PA::Vector2i{12, 9}},
            {Wall::AWall::WallPosition::TRI_LEFT, PA::Vector2i{13, 10}},
            {Wall::AWall::WallPosition::TRI_RIGHT, PA::Vector2i{12, 10}},
        };
        this->price = 50;
    }

    void Brick::update() {

    }
}