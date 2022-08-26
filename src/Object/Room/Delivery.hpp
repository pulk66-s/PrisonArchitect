#ifndef __OBJECT_ROOM_DELIVERY_HPP__
    #define __OBJECT_ROOM_DELIVERY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "ARoom.hpp"

class PA::Object::Room::Delivery : public PA::Object::Room::ARoom {
    public:
    Delivery(PA::Vector2i dim, PA::Vector2i pos={0,0});
    using ARoom::draw;
};

#endif
