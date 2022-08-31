#ifndef __PA_OBJECT_ITEMS_ITEMS_HPP__
    #define __PA_OBJECT_ITEMS_ITEMS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Items/AItem.hpp"
    #include "Global/Vector.hpp"
    #include <map>
    #include <memory>
    #include <functional>

class PA::Object::Item::Items {

    private:
    std::map<PA::Vector2<int>, std::shared_ptr<AItem>> items = {};

    public:
    static std::shared_ptr<Items> getInstance();
    std::map<PA::Vector2<int>, std::shared_ptr<AItem>> *getItems();
    void add(PA::Vector2<int> pos, std::shared_ptr<AItem> item);
    std::shared_ptr<AItem> get(PA::Vector2<int> pos);
    bool exist(PA::Vector2<int> pos);
    std::shared_ptr<AItem> findIf(std::function<bool(std::shared_ptr<AItem>)> func);
    void remove(PA::Vector2<int> pos);

};

#endif