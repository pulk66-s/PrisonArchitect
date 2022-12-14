#ifndef __PA_OBJECT_TILE_WALL_MANAGER_HPP__
    #define __PA_OBJECT_TILE_WALL_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Wall/AWall.hpp"
    #include "Object/Tile/Factory.hpp"
    #include "Object/Items/ItemManager.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/PNJ/Tasks/Manager.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include <memory>
    #include <unordered_map>
    #include <unordered_set>
    #include <map>

class PA::Object::Tile::Wall::Manager {

    private:
    std::shared_ptr<PA::Object::PlayerInfo> playerInfo = PA::Object::PlayerInfo::getInstance();
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Event> event = PA::Lib::SDL2::Event::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
    std::shared_ptr<Tiles> tiles = Tiles::getInstance();

    Item::ItemManager itemManager;
    PNJ::Task::Manager taskManager;
    std::shared_ptr<PA::Vector2<int>> firstPos = nullptr;
    std::shared_ptr<AWall> firstTile = nullptr;
    std::unordered_set<std::shared_ptr<ITile>> tilesPreviewSet = {};
    bool tilesCreation = false;
    bool waitForRelease = true;
    std::string tileName = "";
    Tile::Factory tileFactory;

    void endTilesCreation();
    void tilesCreationUpdate();
    void placeTilesPreview();
    void triggerColliderRedirection(std::shared_ptr<ITile> tile);

    public:
    void createWall(std::shared_ptr<AWall> tile);
    void update();
    void draw();
    static std::shared_ptr<Manager> getInstance();

};

#endif