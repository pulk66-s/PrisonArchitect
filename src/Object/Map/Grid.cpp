#include "Object/Map/Grid.hpp"

namespace PA::Object::Map {

    std::shared_ptr<Grid> Grid::getInstance() {
        static std::shared_ptr<Grid> instance = std::make_shared<Grid>();
        return (instance);
    }

    PA::Vector2i Grid::getSquareDim() {
        return (this->squareDim);
    }

    PA::Vector2i Grid::transformPos(PA::Vector2i pos) {
        PA::Vector2i camPos = this->camera->getPos();
        PA::Vector2i mousePos = this->event->getMousePosition();
        PA::Vector2i finalPos = pos - (pos % this->squareDim) - (camPos % this->squareDim);
        if (mousePos.x % this->squareDim.x > this->squareDim.x - camPos.x % this->squareDim.x) {
            finalPos.x += this->squareDim.x;
        }
        if (mousePos.y % this->squareDim.y > this->squareDim.y - camPos.y % this->squareDim.y) {
            finalPos.y += this->squareDim.y;
        }
        return (finalPos);
    }

}