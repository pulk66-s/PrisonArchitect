#include "Object/Tile/Factory.hpp"

namespace PA::Object::Tile {

    Factory::Factory() {
        this->lambdaMap["brickWall"] = CREATE_LAMBDA(Wall::Brick);
        this->lambdaMap["delivery"] = CREATE_LAMBDA(Room::Delivery);
        this->lambdaMap["preview"] = CREATE_LAMBDA(Wall::Preview);
    }

    std::shared_ptr<PA::Object::Tile::ATile> Factory::create(std::string wall, PA::Vector2<int> index, PA::Vector2<int> pos) {
        if (this->lambdaMap.find(wall) == this->lambdaMap.end()) {
            throw PA::Error::InvalidArgument("wall not existing " + wall, __FILE__);
        }
        return (this->lambdaMap[wall](index, pos));
    }

}
