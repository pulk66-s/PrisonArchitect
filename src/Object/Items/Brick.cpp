#include "Object/Items/Brick.hpp"

namespace PA::Object::Item {

    Brick::Brick() 
    : AItem("brick") {
        this->setSpriteSheet(
            "res/sprites/items/bricks.png",
            PA::Vector2<int>(1, 1)
        );
    }

}