#include "Object/Tile/Room/Manager.hpp"

namespace PA::Object::Tile::Room {

    std::shared_ptr<Manager> Manager::create(std::map<PA::Vector2i, std::shared_ptr<ITile>> *tiles) {
        static std::shared_ptr<Manager> instance = std::make_shared<Manager>(tiles);
        return (instance);
    }

    std::shared_ptr<Manager> Manager::getInstance() {
        return (Manager::create());
    }

    Manager::Manager(std::map<PA::Vector2i, std::shared_ptr<ITile>> *tiles) {
        this->tiles = tiles;
    }

    void Manager::roomCreationUpdate() {
        PA::Vector2i mousePos = this->event->getMousePosition();
        PA::Vector2i mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2i camPos = this->camera->getPos();
        PA::Vector2i gridDim = this->grid->getSquareDim();
        if (this->event->isRightClick()) {
            this->endCreation();
        }
        if (this->firstPos == nullptr) {
            this->roomCreationRect->setPos(mousePosGrid);
            if (this->event->isClick()) {
                PA::Vector2i rectPos = mousePosGrid + camPos;
                this->firstPos = std::make_unique<PA::Vector2i>(rectPos);
                this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::MOVABLE);
                this->roomCreationRect->setPos(rectPos);
                this->waitForRelease = true;
            }
        } else {
            PA::Vector2i rectDim = mousePosGrid + camPos - *this->firstPos;
            PA::Vector2i rectPos = *this->firstPos;
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

    void Manager::addRoomToGrid(PA::Vector2i pos, PA::Vector2i dim) {
        for (int i = pos.x; i < pos.x + dim.x; i++) {
            for (int j = pos.y; j < pos.y + dim.y; j++) {
                PA::Vector2i tilePos = PA::Vector2i(i, j) * this->grid->getSquareDim();
                (*this->tiles)[tilePos] = this->tileFactory.create(this->tile->getName(), {0, 0}, tilePos);
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
        PA::Vector2i squareDim = this->grid->getSquareDim();
        this->roomCreationRect = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2i(0, 0), squareDim, SDL_Color{0, 200, 0, 200}, true,
            PA::Lib::SDL2::Camera::Status::FIXED
        );
    }

    std::vector<PA::Vector2i> Manager::getRoomPos(std::string name) {
        std::vector<PA::Vector2i> pos = {};
        if (this->tiles == nullptr) {
            throw PA::Error::NullPtr("tiles", __FILE__);
        }
        for (auto tile : *this->tiles) {
            if (tile.second->getName() == name) {
                pos.push_back(tile.first);
            }
        }
        return (pos);
    }


}