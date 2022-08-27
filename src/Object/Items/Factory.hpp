#ifndef __PA_OBJECT_ITEMS_FACTORY_HPP__
    #define __PA_OBJECT_ITEMS_FACTORY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Items/AItem.hpp"
    #include "Object/Items/Brick.hpp"
    #include <memory>
    #include <functional>
    #include <string>
    #include <unordered_map>

    #define CREATE_ITEM_LAMBDA(className) []() \
        -> std::shared_ptr<AItem> { \
            return (std::make_shared<className>()); \
        }

class PA::Object::Item::Factory {

    private:
    std::unordered_map<std::string, std::function<std::shared_ptr<AItem>()>> factory;

    public:
    Factory();
    std::shared_ptr<AItem> createItem(std::string name);

};

#endif