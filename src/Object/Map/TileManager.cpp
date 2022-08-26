#include "TileManager.hpp"

namespace KA::Object {

    TileManager::TileManager() {
        this->grid = KA::Object::Grid::getInstance();
        this->wallNames = {
            {KA::Object::Grid::Action::CREATE_BRICK_WALL, "brickWall"},
        };
        this->colliders = {};
    }

    void TileManager::changingTileIndex(std::shared_ptr<KA::Object::Tile::ITile> &tile, std::unordered_map<std::string, bool> dir) {
        if (dir["up"] && dir["down"] && dir["left"] && dir["right"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::CROSS);
        else if (dir["up"] && dir["down"] && dir["left"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::TRI_LEFT);
        else if (dir["up"] && dir["down"] && dir["right"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::TRI_RIGHT);
        else if (dir["left"] && dir["right"] && dir["up"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::TRI_UP);
        else if (dir["left"] && dir["right"] && dir["down"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::TRI_DOWN);
        else if (dir["right"] && dir["down"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::CORNER_UPPER_LEFT);
        else if (dir["left"] && dir["down"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::CORNER_UPPER_RIGHT);
        else if (dir["right"] && dir["up"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::CORNER_LOWER_LEFT);
        else if (dir["left"] && dir["up"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::CORNER_LOWER_RIGHT);
        else if (dir["up"] && dir["down"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::COLUMN);
        else if (dir["left"] && dir["right"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::LINE);
        else if (dir["left"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::RIGHT);
        else if (dir["right"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::LEFT);
        else if (dir["up"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::DOWN);
        else if (dir["down"])
            tile->setWallPosition(KA::Object::Tile::ITile::WallPosition::UP);
    }

    void TileManager::createTiles(KA::Object::Grid::Action action) {
        std::vector<KA::Object::Grid::WallInfo> walls = this->grid->getWallsInfo();
        for (auto wall : walls) {
            KA::Vector2i position = wall.pos;
            KA::Vector2i index = wall.index;
            std::shared_ptr<KA::Object::Tile::ITile> tile = this->TileFactory.create(this->wallNames[action], index, position);
            this->colliders[position] = tile;
        }
        KA::Vector2i gridDim = this->grid->getDim();
        std::unordered_map<std::string, KA::Vector2i> buff = {
            {"up", KA::Vector2i{0, -1 * gridDim.y}},
            {"down", KA::Vector2i{0, 1 * gridDim.y}},
            {"left", KA::Vector2i{-1 * gridDim.x, 0}},
            {"right", KA::Vector2i{1 * gridDim.x, 0}},
        };
        for (auto wall : walls) {
            KA::Vector2i position = wall.pos;
            std::shared_ptr<KA::Object::Tile::ITile> tile = this->colliders[position];
            std::unordered_map<std::string, bool> directions = {
                {"up", this->getTile(position + buff["up"]) != nullptr},
                {"down", this->getTile(position + buff["down"]) != nullptr},
                {"left", this->getTile(position + buff["left"]) != nullptr},
                {"right", this->getTile(position + buff["right"]) != nullptr},
            };
            this->changingTileIndex(tile, directions);
            for (auto direction : directions) {
                if (direction.second) {
                    KA::Vector2i subPos = position + buff[direction.first];
                    std::unordered_map<std::string, bool> subDirections = {
                        {"up", this->getTile(subPos + buff["up"]) != nullptr},
                        {"down", this->getTile(subPos + buff["down"]) != nullptr},
                        {"left", this->getTile(subPos + buff["left"]) != nullptr},
                        {"right", this->getTile(subPos + buff["right"]) != nullptr},
                    };
                    tile = this->colliders[subPos];
                    this->changingTileIndex(tile, subDirections);
                }
            }
        }
    }

    void TileManager::draw() {
        for (auto wall : this->colliders) {
            if (wall.second != nullptr) {
                wall.second->draw();
            }
        }
    }

    std::shared_ptr<KA::Object::Tile::ITile> TileManager::getTile(KA::Vector2i index) {
        if (this->colliders.find(index) != this->colliders.end()) {
            return (this->colliders[index]);
        }
        return (nullptr);
    }

    std::shared_ptr<TileManager> TileManager::getInstance() {
        static std::shared_ptr<TileManager> instance = std::make_shared<TileManager>();
        return (instance);
    }

}