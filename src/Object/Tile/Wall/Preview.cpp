#include "Object/Tile/Wall/Preview.hpp"

namespace PA::Object::Tile::Wall {

    Preview::Preview(PA::Vector2i index, PA::Vector2i pos) {
        this->name = "preview";
        this->colliding = false;
        this->createSpriteSheet(pos, index);
        this->price = 0;
        this->wallPositions = {
            {Wall::AWall::WallPosition::CROSS, PA::Vector2i{19, 2}},
            {Wall::AWall::WallPosition::CORNER_UPPER_LEFT, PA::Vector2i{15, 0}},
            {Wall::AWall::WallPosition::CORNER_UPPER_RIGHT, PA::Vector2i{16, 0}},
            {Wall::AWall::WallPosition::CORNER_LOWER_LEFT, PA::Vector2i{15, 1}},
            {Wall::AWall::WallPosition::CORNER_LOWER_RIGHT, PA::Vector2i{16, 1}},
            {Wall::AWall::WallPosition::COLUMN, PA::Vector2i{13, 0}},
            {Wall::AWall::WallPosition::LINE, PA::Vector2i{14, 0}},
            {Wall::AWall::WallPosition::LEFT, PA::Vector2i{14, 1}},
            {Wall::AWall::WallPosition::RIGHT, PA::Vector2i{14, 2}},
            {Wall::AWall::WallPosition::UP, PA::Vector2i{13, 1}},
            {Wall::AWall::WallPosition::DOWN, PA::Vector2i{13, 2}},
            {Wall::AWall::WallPosition::TRI_DOWN, PA::Vector2i{17, 0}},
            {Wall::AWall::WallPosition::TRI_UP, PA::Vector2i{17, 1}},
            {Wall::AWall::WallPosition::TRI_LEFT, PA::Vector2i{18, 2}},
            {Wall::AWall::WallPosition::TRI_RIGHT, PA::Vector2i{17, 2}},
        };
        this->neededItems = {
            {"brickWall", "brick"}
        };
    }

    void Preview::setBuildWall(std::string wall) {
        this->buildWall = this->neededItems[wall];
    }

}