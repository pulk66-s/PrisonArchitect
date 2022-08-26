#ifndef __OBJECT_TILE_MANAGER_HPP__
    #define __OBJECT_TILE_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/TileFactory.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include <map>
    #include <unordered_map>
    #include <vector>
    #include <memory>

class PA::Object::Tile::TileManager {

    private:
    std::shared_ptr<PA::Object::Map::Grid> grid;
    std::map<PA::Vector2i, std::shared_ptr<PA::Object::Tile::ITile>> colliders;
    std::unordered_map<PA::Object::Map::Grid::Action, std::string> wallNames;
    PA::Object::Tile::Factory TileFactory;
    void changingTileIndex(std::shared_ptr<PA::Object::Tile::ITile> &tile, std::unordered_map<std::string, bool> directions);

    public:
    TileManager();
    std::shared_ptr<PA::Object::Tile::ITile> getTile(PA::Vector2i index);
    void createTiles(PA::Object::Map::Grid::Action action);
    void draw();
    static std::shared_ptr<TileManager> getInstance();

};

#endif