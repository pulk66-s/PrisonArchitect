#include "Object/Items/ItemManager.hpp"

namespace PA::Object::Item {

    void ItemManager::draw() {
        for (auto item : this->items) {
            item->draw();
        }
    }

    void ItemManager::createItem(std::string name) {
        this->items.push_back(this->itemFactory.createItem(name));
    }

    void ItemManager::createItem(std::string name, std::size_t times) {
        for (std::size_t i = 0; i < times; i++) {
            this->items.push_back(this->itemFactory.createItem(name));
        }
    }

}