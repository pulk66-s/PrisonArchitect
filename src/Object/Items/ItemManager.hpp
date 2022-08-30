#ifndef __PA_ITEMS_ITEMMANAGER_HPP__
    #define __PA_ITEMS_ITEMMANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Items/Factory.hpp"
    #include "Object/Tile/Room/Manager.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Items/Items.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/NullPtr.hpp"
    #include <vector>

class PA::Object::Item::ItemManager {

    private:
    std::shared_ptr<Tile::Room::Manager> roomManager = Tile::Room::Manager::getInstance();
    std::shared_ptr<Map::Grid> grid = Map::Grid::getInstance();
    Factory itemFactory;
    std::shared_ptr<Items> items = Items::getInstance();

    public:
    void draw();
    void createItem(std::string name);
    bool isFree(PA::Vector2<int> pos);

};

#endif