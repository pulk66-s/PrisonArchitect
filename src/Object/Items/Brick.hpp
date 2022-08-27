#ifndef __PA_OBJECT_ITEMS_BRICK_HPP__
    #define __PA_OBJECT_ITEMS_BRICK_HPP__

    #include "Object/Items/AItem.hpp"
    #include "Object/ObjectNamespace.hpp"

class PA::Object::Item::Brick : public PA::Object::Item::AItem {
    public:
    Brick();
    using AItem::draw;

};

#endif