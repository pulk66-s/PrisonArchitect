#ifndef __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__
    #define __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include "Object/Items/Items.hpp"
    #include "Object/Tile/Tiles.hpp"
    #include "Object/Tile/Factory.hpp"
    #include <iostream>

class PA::Object::PNJ::Task::WallTask : public PA::Object::PNJ::Task::ATask {
    
    private:
    std::shared_ptr<Map::Grid> grid = Map::Grid::getInstance();
    std::shared_ptr<Item::Items> items = Item::Items::getInstance();
    std::shared_ptr<Tile::Tiles> tiles = Tile::Tiles::getInstance();
    Tile::Factory factory;

    PA::Vector2<int> wallPos = {0, 0};

    void updateTask();

    public:
    WallTask();
    void init();
    void update();

};

#endif