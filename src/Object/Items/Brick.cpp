#include "Object/Items/Brick.hpp"

namespace PA::Object::Item {

    Brick::Brick() 
    : AItem("brick") {
        this->setSpriteSheet(
            "res/sprites/items/bricks.png",
            PA::Vector2i(1, 1)
        );
    }

}