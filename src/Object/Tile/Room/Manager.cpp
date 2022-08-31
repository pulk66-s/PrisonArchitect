#include "Object/Tile/Room/Manager.hpp"

namespace PA::Object::Tile::Room {

    std::shared_ptr<Manager> Manager::getInstance() {
        static std::shared_ptr<Manager> instance = std::make_shared<Manager>();
        return (instance);
    }

    void Manager::roomCreationUpdate() {
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2<int> camPos = this->camera->getPos();
        PA::Vector2<int> gridDim = this->grid->getSquareDim();
        if (this->event->isRightClick()) {
            this->endCreation();
        }
        if (this->firstPos == nullptr) {
            this->roomCreationRect->setPos(mousePosGrid);
            if (this->event->isClick()) {
                PA::Vector2<int> rectPos = mousePosGrid + camPos;
                this->firstPos = std::make_unique<PA::Vector2<int>>(rectPos);
                this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::MOVABLE);
                this->roomCreationRect->setPos(rectPos);
                this->waitForRelease = true;
            }
        } else {
            PA::Vector2<int> rectDim = mousePosGrid + camPos - *this->firstPos;
            PA::Vector2<int> rectPos = *this->firstPos;
            if (rectDim.x < 0) {
                rectPos.x += gridDim.x;
                rectDim.x -= gridDim.x;
            } else {
                rectDim.x += gridDim.x;
            }
            if (rectDim.y < 0) {
                rectPos.y += gridDim.y;
                rectDim.y -= gridDim.y;
            } else {
                rectDim.y += gridDim.y;
            }
            this->roomCreationRect->setPos(rectPos);
            this->roomCreationRect->setDim(rectDim);
            if (this->event->isClick()) {
                rectPos /= gridDim;
                rectDim /= gridDim;
                if (rectDim.x < 0) {
                    rectDim.x *= -1;
                    rectPos.x -= (rectDim.x);
                }
                if (rectDim.y < 0) {
                    rectDim.y *= -1;
                    rectPos.y -= (rectDim.y);
                }
                this->addRoomToGrid(rectPos, rectDim);
            }
        }
    }

    void Manager::addRoomToGrid(PA::Vector2<int> pos, PA::Vector2<int> dim) {
        for (int i = pos.x; i < pos.x + dim.x; i++) {
            for (int j = pos.y; j < pos.y + dim.y; j++) {
                PA::Vector2<int> tilePos = PA::Vector2<int>(i, j) * this->grid->getSquareDim();
                this->tiles->addTile(tilePos, this->tileFactory.create(this->tile->getName(), {0, 0}, tilePos));
            }
        }
        this->firstPos = nullptr;
        this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
        this->roomCreationRect->setDim(this->grid->getSquareDim());
        this->waitForRelease = true;
    }

    void Manager::endCreation() {
        this->roomCreation = false;
        this->firstPos = nullptr;
        this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
    }

    void Manager::update() {
        if (this->waitForRelease) {
            if (this->event->isRelease()) {
                this->waitForRelease = false;
            } else {
                return;
            }
        }
        if (this->roomCreation) {
            this->roomCreationUpdate();
        }
    }

    void Manager::draw() {
        if (this->roomCreation) {
            this->roomCreationRect->draw();
        }
    }

    void Manager::createRoom(std::shared_ptr<ITile> tile) {
        this->roomCreation = true;
        this->waitForRelease = true;
        this->tile = tile;
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        this->roomCreationRect = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2<int>(0, 0), squareDim, SDL_Color{0, 200, 0, 200}, true,
            PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    std::vector<PA::Vector2<int>> Manager::getRoomPos(std::string name) {
        std::vector<PA::Vector2<int>> pos = {};
        for (auto tile : *this->tiles->get()) {
            if (tile.second->getName() == name) {
                pos.push_back(tile.first);
            }
        }
        return (pos);
    }


}