#ifndef __OBJECT_MAP_HPP__
    #define __OBJECT_MAP_HPP__

    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Error/NotEnoughMoney.hpp"
    #include "Global/Error/NotifSuccess.hpp"
    #include "Global/Vector.hpp"
    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/PnjManager.hpp"
    #include "Object/PNJ/Tasks/Manager.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Map/Background.hpp"
    #include "Object/Tile/TileManager.hpp"
    #include "Object/Tile/Room/Manager.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Factory.hpp"
    #include "Object/Menu/GameUI.hpp"
    #include "Object/Items/ItemManager.hpp"
    #include <unordered_map>
    #include <map>
    #include <memory>

class PA::Object::Map::Map {

    private:
    std::shared_ptr<PA::Object::Tile::TileManager> tileManager = PA::Object::Tile::TileManager::getInstance();
    PA::Object::Item::ItemManager itemManager;
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
    PA::Object::PNJ::PnjManager pnjManager;
    PNJ::Task::Manager taskManager;

    PA::Object::Menu::GameUI gameUI;
    PA::Object::Map::Background background;

    public:
    void update();
    void draw();

};

#endif