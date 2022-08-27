#include "Object/Items/Factory.hpp"

namespace PA::Object::Item {

    Factory::Factory() {
        this->factory["brick"] = CREATE_ITEM_LAMBDA(Brick);
    };

    std::shared_ptr<AItem> Factory::createItem(std::string name) {
        if (this->factory.find(name) != this->factory.end()) {
            return (this->factory[name]());
        }
        return (nullptr);
    }

}