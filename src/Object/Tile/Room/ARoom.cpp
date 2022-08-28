#include "Object/Tile/Room/ARoom.hpp"

namespace PA::Object::Tile::Room {
    
    ARoom::ARoom(__attribute__((unused))PA::Vector2<int> index, PA::Vector2<int> pos, std::string name) {
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        this->backGround.push_back(PA::Lib::SDL2::Shape::Rectangle(
            pos, squareDim / 2, SDL_Color{200, 200, 200, 200}, true
        ));
        this->backGround.push_back(PA::Lib::SDL2::Shape::Rectangle(
            pos + squareDim / 2, squareDim / 2, SDL_Color{200, 200, 200, 200}, true
        ));
        this->name = name;
    }

    void ARoom::update() {

    }

    void ARoom::draw() {
        for (auto& rectangle : backGround) {
            rectangle.draw();
        }
    }

    void ARoom::setPos(PA::Vector2<int> pos) {
        for (auto& rectangle : backGround) {
            rectangle.setPos(pos);
        }
    }

    PA::Vector2<int> ARoom::getPos() const {
        return (this->backGround[0].getPos());
    }

}