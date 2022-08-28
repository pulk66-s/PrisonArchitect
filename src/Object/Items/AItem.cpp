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

    void AItem::setSpriteSheet(std::string path, PA::Vector2<int> nbSprite) {
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        this->spriteSheet = std::make_unique<PA::Lib::SDL2::Graphic::SpriteSheet>(
            path, nbSprite, PA::Vector2<int>(0, 0), squareDim
        );
    }

    void AItem::setPos(PA::Vector2<int> pos) {
        this->spriteSheet->setPos(pos);
    }

}