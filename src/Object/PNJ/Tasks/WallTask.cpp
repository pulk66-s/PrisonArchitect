#include "Object/PNJ/Tasks/WallTask.hpp"

namespace PA::Object::PNJ::Task {
    
    WallTask::WallTask()
    : ATask("WallTask", "Constructing a wall")
    {

    }

    void WallTask::updateTask() {

    }

    void WallTask::init() {
        std::shared_ptr<Item::AItem> item = this->items->findIf([](std::shared_ptr<Item::AItem> item) {
            return (item->isFree());
        });
        if (item != nullptr) {
            item->setFree(false);
            this->addGoTo(item->getPos());
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
            this->addGoTo(wall->getPos());
        }
    }

    void WallTask::update() {
        if (this->status == NOT_STARTED) {
            this->status = IN_PROGRESS;
            this->init();
        }
        if (!this->itemCarry) {
            if (this->arrived) {
                this->popGoTo();
                this->arrived = false;
                this->action = ATask::GET_ITEM;
            }
        } else {
            this->updateTask();
        }
    }

}