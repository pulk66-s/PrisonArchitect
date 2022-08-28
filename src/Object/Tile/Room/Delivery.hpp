#ifndef __PA_OBJECT_TILE_ROOM_DELIVERY_HPP__
    #define __PA_OBJECT_TILE_ROOM_DELIVERY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/Room/ARoom.hpp"

class PA::Object::Tile::Room::Delivery : public PA::Object::Tile::Room::ARoom {

    public:
    Delivery(PA::Vector2<int> index, PA::Vector2<int> pos);
    using ARoom::update;
    using ARoom::draw;

};

#endif