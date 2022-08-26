#include "TileFactory.hpp"

namespace PA::Object::Tile {

    Factory::Factory() {
        this->lambdaMap["brickWall"] = CREATE_LAMBDA(PA::Object::Tile::BrickWall);
    }

    std::shared_ptr<PA::Object::Tile::ITile> Factory::create(std::string wall, PA::Vector2i index, PA::Vector2i pos) {
        return (this->lambdaMap[wall](index, pos));
    }

}
