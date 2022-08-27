#ifndef __PA_ITEMS_ITEMMANAGER_HPP__
    #define __PA_ITEMS_ITEMMANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Items/AItem.hpp"
    #include "Object/Items/Factory.hpp"
    #include <vector>

class PA::Object::Item::ItemManager {

    private:
    Factory itemFactory;
    std::vector<std::shared_ptr<AItem>> items = {};

    public:
    void draw();
    void createItem(std::string name);
    void createItem(std::string name, std::size_t times);

};

#endif