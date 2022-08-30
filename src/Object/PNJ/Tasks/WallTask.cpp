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
            this->item = item;
            item->setFree(false);
            this->setGoTo(item->getPos());
        }
    }

    void WallTask::updateTask() {

    }

    void WallTask::update() {
        if (this->item == nullptr) {
            this->findItem();
        } else {
            this->updateTask();
        }
    }

}