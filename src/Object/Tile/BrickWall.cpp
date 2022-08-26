#include "BrickWall.hpp"

namespace KA::Object::Tile
{
    BrickWall::BrickWall(KA::Vector2i index, KA::Vector2i pos)
    {
        this->colliding = true;
        this->name = "brickWall";
        KA::Vector2i gridDim = this->grid->getDim();
        this->image = std::make_shared<KA::Lib::SDL2::Image>(
            "res/sprites/game/walls.png", gridDim, pos,
            true, KA::Vector2i{32, 32}
        );
        this->image->setIndex(index);
        this->wallPositions = {
            {KA::Object::Tile::ITile::WallPosition::CROSS, KA::Vector2i{14, 10}},
            {KA::Object::Tile::ITile::WallPosition::CORNER_UPPER_LEFT, KA::Vector2i{10, 8}},
            {KA::Object::Tile::ITile::WallPosition::CORNER_UPPER_RIGHT, KA::Vector2i{11, 8}},
            {KA::Object::Tile::ITile::WallPosition::CORNER_LOWER_LEFT, KA::Vector2i{10, 9}},
            {KA::Object::Tile::ITile::WallPosition::CORNER_LOWER_RIGHT, KA::Vector2i{11, 9}},
            {KA::Object::Tile::ITile::WallPosition::COLUMN, KA::Vector2i{8, 8}},
            {KA::Object::Tile::ITile::WallPosition::LINE, KA::Vector2i{9, 8}},
            {KA::Object::Tile::ITile::WallPosition::LEFT, KA::Vector2i{9, 9}},
            {KA::Object::Tile::ITile::WallPosition::RIGHT, KA::Vector2i{9, 10}},
            {KA::Object::Tile::ITile::WallPosition::UP, KA::Vector2i{8, 9}},
            {KA::Object::Tile::ITile::WallPosition::DOWN, KA::Vector2i{8, 10}},
            {KA::Object::Tile::ITile::WallPosition::TRI_DOWN, KA::Vector2i{12, 8}},
            {KA::Object::Tile::ITile::WallPosition::TRI_UP, KA::Vector2i{12, 9}},
            {KA::Object::Tile::ITile::WallPosition::TRI_LEFT, KA::Vector2i{13, 10}},
            {KA::Object::Tile::ITile::WallPosition::TRI_RIGHT, KA::Vector2i{12, 10}},
        };
    }

    void BrickWall::update() {

    }
}