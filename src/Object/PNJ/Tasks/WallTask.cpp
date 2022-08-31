#include "Object/PNJ/Tasks/WallTask.hpp"

namespace PA::Object::PNJ::Task {
    
    WallTask::WallTask()
    : ATask("WallTask", "Constructing a wall")
    {

    }

    void WallTask::updateTask() {
        if (this->getGoToSize() == 0) {
            this->action = THROW_ITEM;
            this->status = DONE;
            std::shared_ptr<Tile::ATile> tile = this->tiles->get(this->wallPos);
            std::shared_ptr<Tile::Wall::Preview> preview = std::dynamic_pointer_cast<Tile::Wall::Preview>(tile);
            if (preview != nullptr) {
                std::shared_ptr<Tile::ATile> wallTile = this->factory.create(preview->getBuildWall(), {0, 0}, this->wallPos);
                std::shared_ptr<Tile::Wall::AWall> wall = nullptr;
                if (dynamic_cast<Tile::Wall::AWall *>(wallTile.get())) {
                    wall = std::dynamic_pointer_cast<Tile::Wall::AWall>(wallTile);
                    wall->setWantRedirection(true);
                    this->tiles->addTile(this->wallPos, wall);
                }
            }
        }
    }

    void WallTask::init() {
        while (this->getGoToSize() > 0)
            this->popGoTo();
        this->status = IN_PROGRESS;
        std::shared_ptr<Item::AItem> item = this->items->findIf([](std::shared_ptr<Item::AItem> item) {
            return (item->isFree());
        });
        if (item != nullptr) {
            item->setFree(false);
            this->addGoTo(item->getPos() + this->grid->getSquareDim() / 4);
            std::shared_ptr<Tile::ATile> tile = this->tiles->get([](std::shared_ptr<Tile::ATile> tile) {
                if (dynamic_cast<Tile::Wall::Preview *>(tile.get()) != nullptr) {
                    if (!tile->isFocused()) {
                        return (true);
                    }
                }
                return (false);
            });
            tile->setFocused(true);
            std::shared_ptr<Tile::Wall::AWall> wall = std::make_shared<Tile::Wall::AWall>(dynamic_cast<Tile::Wall::AWall *>(tile.get()));
            this->wallPos = wall->getPos();
            this->addGoTo(wall->getPos() + this->grid->getSquareDim() / 4);
        }
    }

    void WallTask::update() {
        if (this->status == NOT_STARTED) {
            this->init();
        }
        if (!this->itemCarry) {
            if (this->arrived) {
                this->popGoTo();
                this->arrived = false;
                this->action = ATask::GET_ITEM;
            }
        } else {
            if (this->arrived) {
                this->popGoTo();
                this->arrived = false;
            }
            this->updateTask();
        }
    }

}