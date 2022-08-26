#include "TileFactory.hpp"

namespace KA::Object::Tile {

    Factory::Factory() {
        this->lambdaMap["brickWall"] = CREATE_LAMBDA(KA::Object::Tile::BrickWall);
    }

    std::shared_ptr<KA::Object::Tile::ITile> Factory::create(std::string wall, KA::Vector2i index, KA::Vector2i pos) {
        return (this->lambdaMap[wall](index, pos));
    }

}
