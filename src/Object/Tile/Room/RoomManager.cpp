#include "RoomManager.hpp"

namespace PA::Object::Tile::Room {

    RoomManager::RoomManager() {
        this->rooms = {
            {
                "delivery", {std::make_shared<Delivery>(PA::Vector2i{3, 3}, PA::Vector2i{0, 0})}
            }
        };
        this->event = PA::Lib::SDL2::Event::getInstance();
        this->roomCreationRect = std::make_unique<PA::Lib::SDL2::Shape::Rectangle>(
            PA::Vector2i{0, 0}, PA::Vector2i{0, 0},
            SDL_Color{0, 200, 0, 255}, true, PA::Lib::SDL2::Camera::Status::FIXED
        );
        this->camera = PA::Lib::SDL2::Camera::getInstance();
        this->grid = PA::Object::Map::Grid::getInstance();
    }

    // PARFAIT DONC ON TOUCHE PAS !!!
    void RoomManager::roomCreationUpdate() {
        PA::Vector2i mousePos = this->event->getMousePosition();
        PA::Vector2i mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2i camPos = this->camera->getPos();
        PA::Vector2i gridDim = this->grid->getSquareDim();
        if (this->roomCreationFirstPoint == nullptr) {
            this->roomCreationRect->setPos(mousePosGrid);
        } else {
            PA::Vector2i absPos = {
                mousePosGrid.x + camPos.x,
                mousePosGrid.y + camPos.y
            };
            PA::Vector2i rectDim = {
                absPos.x - this->roomCreationFirstPoint->x,
                absPos.y - this->roomCreationFirstPoint->y
            };
            PA::Vector2i currPos = *this->roomCreationFirstPoint;
            PA::Vector2i toAdd = {0, 0};
            if (rectDim.x < 0) {
                toAdd.x += gridDim.x;
                rectDim.x -= gridDim.x;
            } else {
                rectDim.x += gridDim.x;
            }
            if (rectDim.y < 0) {
                toAdd.y += gridDim.y;
                rectDim.y -= gridDim.y;
            } else {
                rectDim.y += gridDim.y;
            }
            this->roomCreationRectDim = rectDim;
            this->roomCreationRect->setPos({currPos.x + toAdd.x, currPos.y + toAdd.y});
            this->roomCreationRect->setDim(rectDim);
        }
        if (this->event->isClick()) {
            if (this->roomCreationFirstPoint == nullptr) {
                PA::Vector2i rectPos = {
                    mousePosGrid.x + camPos.x,
                    mousePosGrid.y + camPos.y
                };
                this->roomCreationFirstPoint = std::make_unique<PA::Vector2i>(rectPos);
                this->roomCreationRect->setPos(rectPos);
                this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::MOVABLE);
            } else {
                PA::Vector2i rectPos = *this->roomCreationFirstPoint;
                PA::Vector2i rectDim = this->roomCreationRectDim;
                rectPos.x /= gridDim.x;
                rectPos.y /= gridDim.y;
                rectDim.x /= gridDim.x;
                rectDim.y /= gridDim.y;
                if (rectDim.x < 0) {
                    rectDim.x *= -1;
                    rectPos.x -= (rectDim.x - 1);
                }
                if (rectDim.y < 0) {
                    rectDim.y *= -1;
                    rectPos.y -= (rectDim.y - 1);
                }
                if (this->rooms.find(this->roomCreationName) == this->rooms.end()) {
                    this->rooms[this->roomCreationName] = {};
                }
                this->rooms[this->roomCreationName].push_back(
                    std::make_shared<Delivery>(rectDim, rectPos)
                );
                this->roomCreation = false;
                this->roomCreationFirstPoint = nullptr;
                this->roomCreationRect->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
            }
            this->waitingForRelease = true;
        }
    }

    void RoomManager::update() {
        if (this->waitingForRelease) {
            if (this->event->isRelease()) {
                this->waitingForRelease = false;
            }
            return;
        }
        if (this->roomCreation) {
            this->roomCreationUpdate();
        }
    }

    void RoomManager::draw() {
        for (auto &room : this->rooms) {
            for (auto &r : room.second) {
                r->draw();
            }
        }
        if (this->roomCreation) {
            this->roomCreationRect->draw();
        }
    }

    void RoomManager::createRoom(std::string name) {
        this->roomCreation = true;
        this->waitingForRelease = true;
        this->roomCreationRect->setDim(this->grid->getSquareDim());
        this->roomCreationName = name;
    }

}
