#ifndef __OBJECT_TILE_MANAGER_HPP__
    #define __OBJECT_TILE_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Factory.hpp"
    #include "Object/Tile/Room/Manager.hpp"
    #include "Object/Tile/Room/ARoom.hpp"
    #include "Object/Tile/Wall/Manager.hpp"
    #include "Object/Tile/Wall/AWall.hpp"
    #include "Global/Vector.hpp"
    #include <map>
    #include <unordered_map>
    #include <vector>
    #include <memory>

class PA::Object::Tile::TileManager {

    private:
    std::shared_ptr<Room::Manager> roomManager = nullptr;
    std::shared_ptr<Wall::Manager> wallManager = nullptr;
    std::shared_ptr<Map::Grid> grid = Map::Grid::getInstance();

    Factory tileFactory;
    std::map<PA::Vector2<int>, std::shared_ptr<ITile>> tiles = {};

    public:
    TileManager();
    std::shared_ptr<ITile> getTile(PA::Vector2<int> index);
    void draw();
    void update();
    static std::shared_ptr<TileManager> getInstance();
    void createTiles(std::string tileName);
    std::shared_ptr<ITile> getCollider(PA::Vector2<int> index);
    void createRoom(std::string name, PA::Vector2<int> pos, PA::Vector2<int> dim);

};

#endif