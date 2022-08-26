#ifndef __OBJECT_ROOM_DELIVERY_HPP__
    #define __OBJECT_ROOM_DELIVERY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "ARoom.hpp"

class KA::Object::Room::Delivery : public KA::Object::Room::ARoom {
    public:
    Delivery(KA::Vector2i dim, KA::Vector2i pos={0,0});
    using ARoom::draw;
};

#endif
