#include "TileManager.hpp"

namespace PA::Object::Tile {

    TileManager::TileManager() {
        this->roomManager = Room::Manager::create(&this->tiles);
        this->wallManager = Wall::Manager::create(&this->tiles);
        this->createRoom("delivery", PA::Vector2i(10, 30), PA::Vector2i(30, 10));
    }

    void TileManager::update() {
        this->wallManager->update();
        this->roomManager->update();
    }

    void TileManager::draw() {
        this->roomManager->draw();
        this->wallManager->draw();
        for (auto wall : this->tiles) {
            if (wall.second != nullptr) {
                wall.second->draw();
            }
        }
    }

    std::shared_ptr<PA::Object::Tile::ITile> TileManager::getTile(PA::Vector2i index) {
        if (this->tiles.find(index) != this->tiles.end()) {
            return (this->tiles[index]);
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
        if (dynamic_cast<Room::ARoom *>(tile.get())) {
            this->roomManager->createRoom(tile);
        } else if (dynamic_cast<Wall::AWall *>(tile.get())) {
            std::shared_ptr<Wall::AWall> wall = std::dynamic_pointer_cast<Wall::AWall>(tile);
            this->wallManager->createWall(wall);
        }
    }

    void TileManager::createRoom(std::string name, PA::Vector2i pos, PA::Vector2i dim) {
        PA::Vector2i squareDim = this->grid->getSquareDim();
        for (int i = pos.x; i < pos.x + dim.x; i++) {
            for (int j = pos.y; j < pos.y + dim.y; j++) {
                PA::Vector2i index = {i, j};
                std::shared_ptr<ITile> room = this->tileFactory.create(name, {0, 0}, index * squareDim);
                this->tiles[index] = room;
            }
        }
    }

}