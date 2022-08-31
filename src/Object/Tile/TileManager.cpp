#include "TileManager.hpp"

namespace PA::Object::Tile {

    TileManager::TileManager() {
        this->createRoom("delivery", PA::Vector2<int>(10, 30), PA::Vector2<int>(30, 10));
    }

    void TileManager::update() {
        this->wallManager->update();
        this->roomManager->update();
    }

    void TileManager::draw() {
        this->roomManager->draw();
        this->wallManager->draw();
        for (auto wall : *this->tiles->get()) {
            if (wall.second != nullptr) {
                wall.second->draw();
            }
        }
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

    void TileManager::createRoom(std::string name, PA::Vector2<int> pos, PA::Vector2<int> dim) {
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        for (int i = pos.x; i < pos.x + dim.x; i++) {
            for (int j = pos.y; j < pos.y + dim.y; j++) {
                PA::Vector2<int> index = {i, j};
                std::shared_ptr<ATile> room = this->tileFactory.create(name, {0, 0}, index * squareDim);
                this->tiles->addTile(index, room);
            }
        }
    }

}