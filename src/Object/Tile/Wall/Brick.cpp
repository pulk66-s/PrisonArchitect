#include "Object/Tile/Wall/Brick.hpp"

namespace PA::Object::Tile::Wall
{
    Brick::Brick(PA::Vector2<int> index, PA::Vector2<int> pos)
    {
        this->colliding = true;
        this->name = "brickWall";
        this->createSpriteSheet(pos, index);
        this->price = 50;
        this->item = "brick";
        this->wallPositions = {
            {Wall::AWall::WallPosition::CROSS, PA::Vector2<int>{14, 10}},
            {Wall::AWall::WallPosition::CORNER_UPPER_LEFT, PA::Vector2<int>{10, 8}},
            {Wall::AWall::WallPosition::CORNER_UPPER_RIGHT, PA::Vector2<int>{11, 8}},
            {Wall::AWall::WallPosition::CORNER_LOWER_LEFT, PA::Vector2<int>{10, 9}},
            {Wall::AWall::WallPosition::CORNER_LOWER_RIGHT, PA::Vector2<int>{11, 9}},
            {Wall::AWall::WallPosition::COLUMN, PA::Vector2<int>{8, 8}},
            {Wall::AWall::WallPosition::LINE, PA::Vector2<int>{9, 8}},
            {Wall::AWall::WallPosition::LEFT, PA::Vector2<int>{9, 9}},
            {Wall::AWall::WallPosition::RIGHT, PA::Vector2<int>{9, 10}},
            {Wall::AWall::WallPosition::UP, PA::Vector2<int>{8, 9}},
            {Wall::AWall::WallPosition::DOWN, PA::Vector2<int>{8, 10}},
            {Wall::AWall::WallPosition::TRI_DOWN, PA::Vector2<int>{12, 8}},
            {Wall::AWall::WallPosition::TRI_UP, PA::Vector2<int>{12, 9}},
            {Wall::AWall::WallPosition::TRI_LEFT, PA::Vector2<int>{13, 10}},
            {Wall::AWall::WallPosition::TRI_RIGHT, PA::Vector2<int>{12, 10}},
        };
    }
}