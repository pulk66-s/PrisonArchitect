#include "TileManager.hpp"

namespace PA::Object::Tile {

    void TileManager::placeTilesPreview() {
        PA::Vector2i mousePos = this->event->getMousePosition();
        PA::Vector2i mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2i camPos = this->camera->getPos();
        PA::Vector2i ending = mousePosGrid + camPos;
        PA::Vector2i starting = *this->firstPos;
        PA::Vector2i gridDim = this->grid->getSquareDim();
        if (starting.x > ending.x) {
            int tmp = starting.x;
            starting.x = ending.x;
            ending.x = tmp;
        }
        if (starting.y > ending.y) {
            int tmp = starting.y;
            starting.y = ending.y;
            ending.y = tmp;
        }
        int sizeX = ((ending.x - starting.x) / gridDim.x + 1) * 2;
        int sizeY = ((ending.y - starting.y) / gridDim.y - 1) * 2;
        std::size_t size = sizeX + sizeY;
        if (size == 0) {
            size = 1;
        }
        if (this->tilesPreviewSet.size() < size) {
            for (int i = this->tilesPreviewSet.size(); i < size; i++) {
                this->tilesPreviewSet.insert(this->tileFactory.create(this->tileName));
            }
        } else if (this->tilesPreviewSet.size() > size) {
            for (int i = this->tilesPreviewSet.size(); i > size; i--) {
                this->tilesPreviewSet.erase(this->tilesPreviewSet.begin());
            }
        }
        int index = 0;
        for (auto tile : this->tilesPreviewSet) {
            if (index < sizeX / 2) {
                PA::Vector2i pos = {starting.x + index * gridDim.x, starting.y};
                tile->setPos(pos);
            } else if (index >= sizeX / 2 && index < sizeX) {
                PA::Vector2i pos = {starting.x + (index - sizeX / 2) * gridDim.x, ending.y};
                tile->setPos(pos);
            } else if (index >= sizeX && index < sizeX + sizeY / 2) {
                PA::Vector2i pos = {starting.x, starting.y + (index - sizeX + 1) * gridDim.y};
                tile->setPos(pos);
            } else {
                PA::Vector2i pos = {ending.x, starting.y + (index - sizeX + 1 - sizeY / 2) * gridDim.y};
                tile->setPos(pos);
            }
            index++;
        }
    }

    void TileManager::endTilesCreation() {
        this->firstPos = nullptr;
        std::shared_ptr<ITile> tile = this->tileFactory.create(tileName, {8, 8});
        if (tile == nullptr) {
            throw PA::Error::InvalidArgument("Invalid tile name", __FILE__);
        }
        this->firstTile = tile;
        for (auto tile : this->tilesPreviewSet) {
            tile->setColliding(true);
            this->colliders.insert({tile->getPos(), tile});
        }
        PA::Vector2i squareDim = this->grid->getSquareDim();
        for (auto tile : this->tilesPreviewSet) {
            PA::Vector2i pos = tile->getPos();
            this->triggerColliderRedirection(this->colliders[pos]);
            if (this->getCollider(tile->getPos() + PA::Vector2i(0, -squareDim.y)) != nullptr) {
                this->triggerColliderRedirection(this->colliders[pos + PA::Vector2i(0, -squareDim.y)]);
            }
            if (this->getCollider(tile->getPos() + PA::Vector2i(squareDim.x, 0)) != nullptr) {
                this->triggerColliderRedirection(this->colliders[pos + PA::Vector2i(squareDim.x, 0)]);
            }
            if (this->getCollider(tile->getPos() + PA::Vector2i(0, squareDim.y)) != nullptr) {
                this->triggerColliderRedirection(this->colliders[pos + PA::Vector2i(0, squareDim.y)]);
            }
            if (this->getCollider(tile->getPos() + PA::Vector2i(-squareDim.x, 0)) != nullptr) {
                this->triggerColliderRedirection(this->colliders[pos + PA::Vector2i(-squareDim.x, 0)]);
            }
        }
        this->tilesPreviewSet.clear();
        this->tilesPreviewSet.insert(this->firstTile);
        this->firstTile->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
    }

    void TileManager::tilesCreationUpdate() {
        PA::Vector2i mousePos = this->event->getMousePosition();
        PA::Vector2i mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2i camPos = this->camera->getPos();
        if (this->event->isRightClick()) {
            this->tilesCreation = false;
            this->tilesPreviewSet.clear();
        }
        if (this->firstPos == nullptr) {
            this->firstTile->setPos(mousePosGrid);
            if (this->event->isClick()) {
                PA::Vector2i tilePos = mousePosGrid + camPos;
                this->firstPos = std::make_shared<PA::Vector2i>(tilePos);
                this->firstTile->setPos(tilePos);
                this->firstTile->setStatus(PA::Lib::SDL2::Camera::Status::MOVABLE);
            }
        } else {
            if (this->event->isRelease()) {
                this->endTilesCreation();
            } else {
                this->placeTilesPreview();
            }
        }
    }

    void TileManager::update() {
        if (this->waitForRelease) {
            if (this->event->isRelease()) {
                this->waitForRelease = false;
            } else {
                return;
            }
        }
        if (this->tilesCreation) {
            this->tilesCreationUpdate();
        }
    }

    void TileManager::draw() {
        for (auto wall : this->colliders) {
            if (wall.second != nullptr) {
                wall.second->draw();
            }
        }
        for (auto tile : this->tilesPreviewSet) {
            if (tile != nullptr) {
                tile->draw();
            }
        }
    }

    std::shared_ptr<PA::Object::Tile::ITile> TileManager::getTile(PA::Vector2i index) {
        if (this->colliders.find(index) != this->colliders.end()) {
            return (this->colliders[index]);
        }
        return (nullptr);
    }

    std::shared_ptr<TileManager> TileManager::getInstance() {
        static std::shared_ptr<TileManager> instance = std::make_shared<TileManager>();
        return (instance);
    }

    void TileManager::createTiles(std::string tileName) {
        std::shared_ptr<ITile> tile = this->tileFactory.create(tileName, {8, 8});
        if (tile == nullptr) {
            throw PA::Error::InvalidArgument("Invalid tile name", __FILE__);
        }
        this->tileName = tileName;
        this->firstTile = tile;
        tile->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
        this->tilesPreviewSet.insert(tile);
        this->tilesCreation = true;
        this->waitForRelease = true;
    }

    std::shared_ptr<ITile> TileManager::getCollider(PA::Vector2i index) {
        if (this->colliders.find(index) != this->colliders.end()) {
            return (this->colliders[index]);
        }
        return (nullptr);
    }

    void TileManager::triggerColliderRedirection(std::shared_ptr<ITile> tile) {
        PA::Vector2i pos = tile->getPos();
        PA::Vector2i gridPos = this->grid->getSquareDim();
        std::unordered_map<std::string, std::shared_ptr<ITile>> tiles = {
            {"up", this->getCollider(pos + PA::Vector2i{0, -gridPos.y})},
            {"down", this->getCollider(pos + PA::Vector2i{0, gridPos.y})},
            {"left", this->getCollider(pos + PA::Vector2i{-gridPos.x, 0})},
            {"right", this->getCollider(pos + PA::Vector2i{gridPos.x, 0})}
        };
        std::unordered_map<std::string, bool> dir = {
            {"up", tiles["up"] != nullptr},
            {"down", tiles["down"] != nullptr},
            {"left", tiles["left"] != nullptr},
            {"right", tiles["right"] != nullptr}
        };
        if (dir["up"] && dir["down"] && dir["left"] && dir["right"]) {
            tile->setWallPosition(ITile::WallPosition::CROSS);
        } else if (dir["up"] && dir["down"] && dir["left"]) {
            tile->setWallPosition(ITile::WallPosition::TRI_LEFT);
        } else if (dir["up"] && dir["down"] && dir["right"]) {
            tile->setWallPosition(ITile::WallPosition::TRI_RIGHT);
        } else if (dir["left"] && dir["right"] && dir["up"]) {
            tile->setWallPosition(ITile::WallPosition::TRI_UP);
        } else if (dir["left"] && dir["right"] && dir["down"]) {
            tile->setWallPosition(ITile::WallPosition::TRI_DOWN);
        } else if (dir["left"] && dir["right"]) {
            tile->setWallPosition(ITile::WallPosition::LINE);
        } else if (dir["up"] && dir["down"]) {
            tile->setWallPosition(ITile::WallPosition::COLUMN);
        } else if (dir["right"] && dir["up"]) {
            tile->setWallPosition(ITile::WallPosition::CORNER_LOWER_LEFT);
        } else if (dir["right"] && dir["down"]) {
            tile->setWallPosition(ITile::WallPosition::CORNER_UPPER_LEFT);
        } else if (dir["left"] && dir["up"]) {
            tile->setWallPosition(ITile::WallPosition::CORNER_LOWER_RIGHT);
        } else if (dir["left"] && dir["down"]) {
            tile->setWallPosition(ITile::WallPosition::CORNER_UPPER_RIGHT);
        } else if (dir["up"]) {
            tile->setWallPosition(ITile::WallPosition::DOWN);
        } else if (dir["down"]) {
            tile->setWallPosition(ITile::WallPosition::UP);
        } else if (dir["left"]) {
            tile->setWallPosition(ITile::WallPosition::RIGHT);
        } else if (dir["right"]) {
            tile->setWallPosition(ITile::WallPosition::LEFT);
        }
    }

}