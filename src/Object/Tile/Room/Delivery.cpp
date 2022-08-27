#include "Object/Tile/Room/Delivery.hpp"

namespace PA::Object::Tile::Room {

    Delivery::Delivery(PA::Vector2i index, PA::Vector2i pos)
    : ARoom(index, pos, "delivery") {
    }

}