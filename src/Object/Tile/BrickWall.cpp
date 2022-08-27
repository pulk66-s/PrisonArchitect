#include "BrickWall.hpp"

namespace PA::Object::Tile
{
    BrickWall::BrickWall(PA::Vector2i index, PA::Vector2i pos)
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
            {PA::Object::Tile::ITile::WallPosition::CROSS, PA::Vector2i{14, 10}},
            {PA::Object::Tile::ITile::WallPosition::CORNER_UPPER_LEFT, PA::Vector2i{10, 8}},
            {PA::Object::Tile::ITile::WallPosition::CORNER_UPPER_RIGHT, PA::Vector2i{11, 8}},
            {PA::Object::Tile::ITile::WallPosition::CORNER_LOWER_LEFT, PA::Vector2i{10, 9}},
            {PA::Object::Tile::ITile::WallPosition::CORNER_LOWER_RIGHT, PA::Vector2i{11, 9}},
            {PA::Object::Tile::ITile::WallPosition::COLUMN, PA::Vector2i{8, 8}},
            {PA::Object::Tile::ITile::WallPosition::LINE, PA::Vector2i{9, 8}},
            {PA::Object::Tile::ITile::WallPosition::LEFT, PA::Vector2i{9, 9}},
            {PA::Object::Tile::ITile::WallPosition::RIGHT, PA::Vector2i{9, 10}},
            {PA::Object::Tile::ITile::WallPosition::UP, PA::Vector2i{8, 9}},
            {PA::Object::Tile::ITile::WallPosition::DOWN, PA::Vector2i{8, 10}},
            {PA::Object::Tile::ITile::WallPosition::TRI_DOWN, PA::Vector2i{12, 8}},
            {PA::Object::Tile::ITile::WallPosition::TRI_UP, PA::Vector2i{12, 9}},
            {PA::Object::Tile::ITile::WallPosition::TRI_LEFT, PA::Vector2i{13, 10}},
            {PA::Object::Tile::ITile::WallPosition::TRI_RIGHT, PA::Vector2i{12, 10}},
        };
        this->price = 50;
    }

    void BrickWall::update() {

    }
}