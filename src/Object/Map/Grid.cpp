#include "Object/Map/Grid.hpp"

namespace PA::Object::Map {

    std::shared_ptr<Grid> Grid::getInstance() {
        static std::shared_ptr<Grid> instance = std::make_shared<Grid>();
        return (instance);
    }

    PA::Vector2<int> Grid::getSquareDim() {
        return (this->squareDim);
    }

    PA::Vector2<int> Grid::transformPos(PA::Vector2<int> pos) {
        PA::Vector2<int> camPos = this->camera->getPos();
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> finalPos = pos - (pos % this->squareDim) - (camPos % this->squareDim);
        if (mousePos.x % this->squareDim.x > this->squareDim.x - camPos.x % this->squareDim.x) {
            finalPos.x += this->squareDim.x;
        }
        if (mousePos.y % this->squareDim.y > this->squareDim.y - camPos.y % this->squareDim.y) {
            finalPos.y += this->squareDim.y;
        }
        return (finalPos);
    }

}