#include "Object/Tile/Wall/Preview.hpp"

namespace PA::Object::Tile::Wall {

    Preview::Preview(PA::Vector2<int> index, PA::Vector2<int> pos) {
        this->name = "preview";
        this->colliding = false;
        this->createSpriteSheet(pos, index);
        this->price = 0;
        this->wallPositions = {
            {Wall::AWall::WallPosition::CROSS, PA::Vector2<int>{19, 2}},
            {Wall::AWall::WallPosition::CORNER_UPPER_LEFT, PA::Vector2<int>{15, 0}},
            {Wall::AWall::WallPosition::CORNER_UPPER_RIGHT, PA::Vector2<int>{16, 0}},
            {Wall::AWall::WallPosition::CORNER_LOWER_LEFT, PA::Vector2<int>{15, 1}},
            {Wall::AWall::WallPosition::CORNER_LOWER_RIGHT, PA::Vector2<int>{16, 1}},
            {Wall::AWall::WallPosition::COLUMN, PA::Vector2<int>{13, 0}},
            {Wall::AWall::WallPosition::LINE, PA::Vector2<int>{14, 0}},
            {Wall::AWall::WallPosition::LEFT, PA::Vector2<int>{14, 1}},
            {Wall::AWall::WallPosition::RIGHT, PA::Vector2<int>{14, 2}},
            {Wall::AWall::WallPosition::UP, PA::Vector2<int>{13, 1}},
            {Wall::AWall::WallPosition::DOWN, PA::Vector2<int>{13, 2}},
            {Wall::AWall::WallPosition::TRI_DOWN, PA::Vector2<int>{17, 0}},
            {Wall::AWall::WallPosition::TRI_UP, PA::Vector2<int>{17, 1}},
            {Wall::AWall::WallPosition::TRI_LEFT, PA::Vector2<int>{18, 2}},
            {Wall::AWall::WallPosition::TRI_RIGHT, PA::Vector2<int>{17, 2}},
        };
    }

    Preview::Preview(Preview *preview) {
        this->name = "preview";
        this->colliding = false;
        this->spriteSheet = preview->spriteSheet;
        this->setPos(preview->getPos());
        this->price = 0;
        this->wallPositions = preview->wallPositions;
    }

    void Preview::setBuildWall(std::string wall) {
        this->buildWall = wall;
    }

    std::string Preview::getBuildWall() const {
        return (this->buildWall);
    }

}