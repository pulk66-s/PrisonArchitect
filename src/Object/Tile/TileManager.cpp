#include "TileManager.hpp"

namespace PA::Object::Tile {

    void TileManager::update() {
        this->wallManager.update();
        this->roomManager.update();
    }

    void TileManager::draw() {
        this->roomManager.draw();
        this->wallManager.draw();
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
            this->roomManager.createRoom(tile, &this->tiles);
        } else if (dynamic_cast<Wall::AWall *>(tile.get())) {
            std::shared_ptr<Wall::AWall> wall = std::dynamic_pointer_cast<Wall::AWall>(tile);
            this->wallManager.createWall(wall, &this->tiles);
        }
    }

}