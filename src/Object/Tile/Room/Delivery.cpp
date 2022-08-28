#include "Object/Tile/Room/Delivery.hpp"

namespace PA::Object::Tile::Room {

    Delivery::Delivery(PA::Vector2<int> index, PA::Vector2<int> pos)
    : ARoom(index, pos, "delivery") {
    }

}