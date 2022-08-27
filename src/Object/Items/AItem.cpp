#include "Object/Items/AItem.hpp"

namespace PA::Object::Item {

    AItem::AItem(std::string name) {
        this->name = name;
    }

    void AItem::draw() {
        if (this->spriteSheet != nullptr) {
            this->spriteSheet->draw();
        }
    }

    void AItem::update() {

    }

    void AItem::setSpriteSheet(std::string path, PA::Vector2i nbSprite) {
        PA::Vector2i squareDim = this->grid->getSquareDim();
        this->spriteSheet = std::make_unique<PA::Lib::SDL2::Graphic::SpriteSheet>(
            path, nbSprite, PA::Vector2i(0, 0), squareDim
        );
    }

}