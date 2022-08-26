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

class KA::Object::TileManager {

    private:
    std::shared_ptr<KA::Object::Grid> grid;
    std::map<KA::Vector2i, std::shared_ptr<KA::Object::Tile::ITile>> colliders;
    std::unordered_map<KA::Object::Grid::Action, std::string> wallNames;
    KA::Object::Tile::Factory TileFactory;
    void changingTileIndex(std::shared_ptr<KA::Object::Tile::ITile> &tile, std::unordered_map<std::string, bool> directions);

    public:
    TileManager();
    std::shared_ptr<KA::Object::Tile::ITile> getTile(KA::Vector2i index);
    void createTiles(KA::Object::Grid::Action action);
    void draw();
    static std::shared_ptr<TileManager> getInstance();

};

#endif