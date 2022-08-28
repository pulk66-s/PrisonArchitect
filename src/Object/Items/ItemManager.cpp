#include "Object/Items/ItemManager.hpp"

namespace PA::Object::Item {

    ItemManager::ItemManager() {
    }

    std::shared_ptr<ItemManager> ItemManager::getInstance() {
        static std::shared_ptr<ItemManager> instance = std::make_shared<ItemManager>();
        return (instance);
    }

    void ItemManager::draw() {
        for (auto item : this->items) {
            item.second->draw();
        }
    }

    void ItemManager::createItem(std::string name) {
        PA::Vector2<int> squareDim = this->grid->getSquareDim();
        std::shared_ptr<AItem> item = this->itemFactory.createItem(name);
        if (item == nullptr) {
            throw PA::Error::NullPtr("Item not found" + name, __FILE__);
        }
        std::vector<PA::Vector2<int>> pos = this->roomManager->getRoomPos("delivery");
        for (PA::Vector2<int> tilePos : pos) {
            if (this->isFree(tilePos)) {
                item->setPos(tilePos * squareDim);
                this->items[tilePos] = item;
                break;
            }
        }
    }

    bool ItemManager::isFree(PA::Vector2<int> pos) {
        if (this->items.find(pos) != this->items.end()) {
            return (false);
        }
        return (true);
    }

}