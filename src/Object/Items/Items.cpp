#include "Object/Items/Items.hpp"

namespace PA::Object::Item {

    std::shared_ptr<Items> Items::getInstance() {
        static std::shared_ptr<Items> instance = std::make_shared<Items>();
        return (instance);
    }

    void Items::add(PA::Vector2<int> pos, std::shared_ptr<AItem> item) {
        this->items.insert(std::pair<PA::Vector2<int>, std::shared_ptr<AItem>>(pos, item));
    }

    bool Items::exist(PA::Vector2<int> pos) {
        return (this->items.find(pos) != this->items.end());
    }

    std::map<PA::Vector2<int>, std::shared_ptr<AItem>> *Items::getItems() {
        return (&this->items);
    }

    std::shared_ptr<AItem> Items::findIf(std::function<bool(std::shared_ptr<AItem>)> func) {
        for (auto item : this->items) {
            if (func(item.second)) {
                return (item.second);
            }
        }
        return (nullptr);
    }

}