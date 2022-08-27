#include "Object/Tile/Factory.hpp"

namespace PA::Object::Tile {

    Factory::Factory() {
        this->lambdaMap["brickWall"] = CREATE_LAMBDA(BrickWall);
        this->lambdaMap["delivery"] = CREATE_LAMBDA(Room::Delivery);
    }

    std::shared_ptr<PA::Object::Tile::ITile> Factory::create(std::string wall, PA::Vector2i index, PA::Vector2i pos) {
        if (this->lambdaMap.find(wall) == this->lambdaMap.end()) {
            throw PA::Error::InvalidArgument("wall not existing " + wall, __FILE__);
        }
        return (this->lambdaMap[wall](index, pos));
    }

}
