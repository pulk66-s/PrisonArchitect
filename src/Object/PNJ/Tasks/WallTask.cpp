#include "Object/PNJ/Tasks/WallTask.hpp"

namespace PA::Object::PNJ::Task {
    
    WallTask::WallTask()
    : ATask("WallTask", "Constructing a wall")
    {

    }

    void WallTask::findItem() {
        std::shared_ptr<Item::AItem> item = this->items->findIf([](std::shared_ptr<Item::AItem> item) {
            return (item->isFree());
        });
        if (item != nullptr) {
            item->setFree(false);
            this->setGoTo(item->getPos());
        }
    }

    void WallTask::updateTask() {

    }

    void WallTask::update() {
        this->status = IN_PROGRESS;
        if (!this->itemCarry) {
            this->findItem();
            if (this->arrived) {
                this->goTo = nullptr;
                this->arrived = false;
                this->action = ATask::GET_ITEM;
            }
        } else {
            this->goTo = std::make_shared<PA::Vector2<int>>(0, 0);
            this->updateTask();
        }
    }

}