#include "Material.hpp"

namespace KA::Object::Menu {

    Material::Material()
    : AIcon({240, 840}, {64, 64}, {2, 0}, "res/sprites/game/walls.png") {
        this->spriteSheetDim = {32, 32};
        this->roomIcons["brickWall"] = CREATE_ICON("brickWall", 120, 620, 48, 48);
        this->roomIcons["brickWall"].icon->setIndex({8, 10});
    }

    KA::Object::Menu::AIcon::Action Material::update() {
        this->AIcon::update();
        if (this->displayed) {
            if (this->roomIcons["brickWall"].icon->isClick()) {
                this->displayed = false;
                return (KA::Object::Menu::AIcon::Action::BRICK_WALL);
            }
        }
        return (KA::Object::Menu::AIcon::Action::NONE);
    }

}