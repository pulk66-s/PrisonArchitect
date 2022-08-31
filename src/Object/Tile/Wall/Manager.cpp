#include "Object/Tile/Wall/Manager.hpp"

namespace PA::Object::Tile::Wall {

    std::shared_ptr<Manager> Manager::getInstance() {
        static std::shared_ptr<Manager> instance = std::make_shared<Manager>();
        return (instance);
    }

    void Manager::createWall(std::shared_ptr<AWall> tile) {
        this->tilesPreviewSet.insert(tile);
        this->firstTile = tile;
        this->tileName = this->firstTile->getName();
        tile->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
        this->tilesPreviewSet.insert(tile);
        this->tilesCreation = true;
        this->waitForRelease = true;
    }

    void Manager::endTilesCreation() {
        this->firstPos = nullptr;
        std::shared_ptr<ITile> factoryTile = this->tileFactory.create(this->tileName, {8, 8});
        std::shared_ptr<AWall> tile = nullptr;
        if (dynamic_cast<AWall *>(factoryTile.get()) != nullptr) {
            tile = std::make_shared<AWall>(dynamic_cast<AWall *>(factoryTile.get()));
        }
        this->firstTile = tile;
        int size = this->tilesPreviewSet.size();
        int price = size * this->firstTile->getPrice();
        try {
            std::cout << "size " << size << std::endl;
            std::cout << "price " << price << std::endl;
            std::cout << "first tile " << this->firstTile->getPrice() << std::endl;
            this->playerInfo->addMoney(-price);
            for (int i = 0; i < size; i++) {
                this->itemManager.createItem(this->firstTile->getItem());
                this->taskManager.createTask(this->firstTile->getTask());
            }
        } catch (PA::Error::NotEnoughMoney &e) {
            this->tilesPreviewSet.clear();
            this->tilesCreation = false;
            this->firstPos = nullptr;
            this->firstTile = nullptr;
            throw e;
        }
        for (auto tile : this->tilesPreviewSet) {
            std::shared_ptr<Preview> preview = std::make_shared<Preview>(PA::Vector2<int>(13, 0), tile->getPos());
            preview->setBuildWall(tile->getName());
            preview->setColliding(true);
            this->tiles->addTile(preview->getPos(), preview);
        }
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        for (auto tile : this->tilesPreviewSet) {
            PA::Vector2<int> pos = tile->getPos();
            this->triggerColliderRedirection(this->tiles->get(pos));
            if (this->tiles->get(tile->getPos() + PA::Vector2<int>(0, -squareDim.y)) != nullptr) {
                this->triggerColliderRedirection(this->tiles->get(pos + PA::Vector2<int>(0, -squareDim.y)));
            }
            if (this->tiles->get(tile->getPos() + PA::Vector2<int>(squareDim.x, 0)) != nullptr) {
                this->triggerColliderRedirection(this->tiles->get(pos + PA::Vector2<int>(squareDim.x, 0)));
            }
            if (this->tiles->get(tile->getPos() + PA::Vector2<int>(0, squareDim.y)) != nullptr) {
                this->triggerColliderRedirection(this->tiles->get(pos + PA::Vector2<int>(0, squareDim.y)));
            }
            if (this->tiles->get(tile->getPos() + PA::Vector2<int>(-squareDim.x, 0)) != nullptr) {
                this->triggerColliderRedirection(this->tiles->get(pos + PA::Vector2<int>(-squareDim.x, 0)));
            }
        }
        this->tilesPreviewSet.clear();
        this->tilesPreviewSet.insert(this->firstTile);
        this->firstTile->setStatus(PA::Lib::SDL2::Camera::Status::FIXED);
    }

    void Manager::tilesCreationUpdate() {
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2<int> camPos = this->camera->getPos();
        if (this->event->isRightClick()) {
            this->tilesCreation = false;
            this->tilesPreviewSet.clear();
        }
        if (this->firstPos == nullptr) {
            this->firstTile->setPos(mousePosGrid);
            if (this->event->isClick()) {
                PA::Vector2<int> tilePos = mousePosGrid + camPos;
                this->firstPos = std::make_shared<PA::Vector2<int>>(tilePos);
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

    void Manager::update() {
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

    void Manager::draw() {
        for (auto tile : this->tilesPreviewSet) {
            if (tile != nullptr) {
                tile->draw();
            }
        }
    }

    void Manager::placeTilesPreview() {
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> mousePosGrid = this->grid->transformPos(mousePos);
        PA::Vector2<int> camPos = this->camera->getPos();
        PA::Vector2<int> ending = mousePosGrid + camPos;
        PA::Vector2<int> starting = *this->firstPos;
        PA::Vector2<int> gridDim = this->grid->getSquareDim();
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
        std::cout << "starting " << starting << " ending " << ending << std::endl;
        int sizeX = (ending.x - starting.x) / gridDim.x + 1;
        int sizeY = (ending.y - starting.y) / gridDim.y + 1;
        std::size_t size = 0;
        std::cout << sizeX << " " << sizeY << std::endl;
        if (sizeX == 1) {
            size = sizeY;
        } else if (sizeY == 1) {
            size = sizeX;
        } else if (sizeX == 2) {
            size = 2 * sizeY;
        } else if (sizeY == 2) {
            size = 2 * sizeX;
        } else {
            size = 2 * sizeX + (2 * (sizeY - 2));
        }
        std::cout << "global size " << size << std::endl;
        std::cout << "sizeX " << sizeX << " sizeY " << sizeY << std::endl;
        std::cout << "tilesPreviewSet size before " << this->tilesPreviewSet.size() << std::endl;
        if (this->tilesPreviewSet.size() < size) {
            for (std::size_t i = this->tilesPreviewSet.size(); i < size; i++) {
                this->tilesPreviewSet.insert(this->tileFactory.create(this->tileName));
            }
        } else if (this->tilesPreviewSet.size() > size) {
            for (std::size_t i = this->tilesPreviewSet.size(); i > size; i--) {
                this->tilesPreviewSet.erase(this->tilesPreviewSet.begin());
            }
        }
        std::cout << "tilesPreviewSet size after " << this->tilesPreviewSet.size() << std::endl;
        std::cout << "starting " << starting << " ending " << ending << std::endl;
        int index = 0;
        for (auto tile : this->tilesPreviewSet) {
            PA::Vector2<int> pos = starting;
            std::cout << "index " << index << std::endl;
            if (index == 0) {
                tile->setPos(pos);
            } else {
                if (sizeX == 0) {
                    pos.y += gridDim.y * index;
                    tile->setPos(pos);
                } else if (sizeY == 0) {
                    pos.x += gridDim.x * index;
                    tile->setPos(pos);
                } else {
                    std::cout << "sizeX " << sizeX << " sizeY " << sizeY << std::endl;
                    if (index < sizeX) {
                        pos.x += gridDim.x * (index);
                        std::cout << "first Line " << pos << std::endl;
                        tile->setPos(pos);
                    } else if (index - sizeX < sizeX) {
                        pos.x += gridDim.x * (index - sizeX);
                        pos.y = ending.y;
                        tile->setPos(pos);
                        std::cout << "second Line " << pos << std::endl;
                    } else if (index - sizeX - sizeX < sizeY - 2) {
                        pos.y += gridDim.y * (index - sizeX - sizeX + 1);
                        tile->setPos(pos);
                        std::cout << "third Line " << pos << std::endl;
                    } else {
                        pos.x = ending.x;
                        pos.y += gridDim.x * (index - sizeX - sizeX - sizeY + 3);
                        tile->setPos(pos);
                        std::cout << "fourth Line " << pos << std::endl;
                    }
                }
            }
            index++;
        }
    }

    void Manager::triggerColliderRedirection(std::shared_ptr<ITile> tileFactory) {
        PA::Vector2<int> pos = tileFactory->getPos();
        PA::Vector2<int> gridPos = this->grid->getSquareDim();
        std::unordered_map<std::string, std::shared_ptr<ITile>> tiles = {
            {"up", this->tiles->get(pos + PA::Vector2<int>{0, -gridPos.y})},
            {"down", this->tiles->get(pos + PA::Vector2<int>{0, gridPos.y})},
            {"left", this->tiles->get(pos + PA::Vector2<int>{-gridPos.x, 0})},
            {"right", this->tiles->get(pos + PA::Vector2<int>{gridPos.x, 0})}
        };
        std::unordered_map<std::string, bool> dir = {
            {"up", tiles["up"] != nullptr},
            {"down", tiles["down"] != nullptr},
            {"left", tiles["left"] != nullptr},
            {"right", tiles["right"] != nullptr}
        };
        std::shared_ptr<AWall> tile;
        if (dynamic_cast<AWall*>(tileFactory.get()) != nullptr) {
            tile = std::make_shared<AWall>(dynamic_cast<AWall *>(tileFactory.get()));
        }
        if (dir["up"] && dir["down"] && dir["left"] && dir["right"]) {
            tile->setWallPosition(AWall::WallPosition::CROSS);
        } else if (dir["up"] && dir["down"] && dir["left"]) {
            tile->setWallPosition(AWall::WallPosition::TRI_LEFT);
        } else if (dir["up"] && dir["down"] && dir["right"]) {
            tile->setWallPosition(AWall::WallPosition::TRI_RIGHT);
        } else if (dir["left"] && dir["right"] && dir["up"]) {
            tile->setWallPosition(AWall::WallPosition::TRI_UP);
        } else if (dir["left"] && dir["right"] && dir["down"]) {
            tile->setWallPosition(AWall::WallPosition::TRI_DOWN);
        } else if (dir["left"] && dir["right"]) {
            tile->setWallPosition(AWall::WallPosition::LINE);
        } else if (dir["up"] && dir["down"]) {
            tile->setWallPosition(AWall::WallPosition::COLUMN);
        } else if (dir["right"] && dir["up"]) {
            tile->setWallPosition(AWall::WallPosition::CORNER_LOWER_LEFT);
        } else if (dir["right"] && dir["down"]) {
            tile->setWallPosition(AWall::WallPosition::CORNER_UPPER_LEFT);
        } else if (dir["left"] && dir["up"]) {
            tile->setWallPosition(AWall::WallPosition::CORNER_LOWER_RIGHT);
        } else if (dir["left"] && dir["down"]) {
            tile->setWallPosition(AWall::WallPosition::CORNER_UPPER_RIGHT);
        } else if (dir["up"]) {
            tile->setWallPosition(AWall::WallPosition::DOWN);
        } else if (dir["down"]) {
            tile->setWallPosition(AWall::WallPosition::UP);
        } else if (dir["left"]) {
            tile->setWallPosition(AWall::WallPosition::RIGHT);
        } else if (dir["right"]) {
            tile->setWallPosition(AWall::WallPosition::LEFT);
        }
    }

}