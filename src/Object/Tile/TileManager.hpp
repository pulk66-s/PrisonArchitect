#ifndef __OBJECT_TILE_MANAGER_HPP__
    #define __OBJECT_TILE_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/PlayerInfo.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Factory.hpp"
    #include "Object/Tile/Tiles.hpp"
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
    std::shared_ptr<Room::Manager> roomManager = Room::Manager::getInstance();
    std::shared_ptr<Wall::Manager> wallManager = Wall::Manager::getInstance();
    std::shared_ptr<Map::Grid> grid = Map::Grid::getInstance();

    Factory tileFactory;
    std::shared_ptr<Tiles> tiles = Tiles::getInstance();

    public:
    TileManager();
    void draw();
    void update();
    static std::shared_ptr<TileManager> getInstance();
    void createTiles(std::string tileName);
    void createRoom(std::string name, PA::Vector2<int> pos, PA::Vector2<int> dim);

};

#endif