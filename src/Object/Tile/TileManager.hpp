#ifndef __OBJECT_TILE_MANAGER_HPP__
    #define __OBJECT_TILE_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/TileFactory.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include <map>
    #include <unordered_map>
    #include <unordered_set>
    #include <vector>
    #include <memory>

class PA::Object::Tile::TileManager {

    private:
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Event> event = PA::Lib::SDL2::Event::getInstance();

    Factory tileFactory;
    std::map<PA::Vector2i, std::shared_ptr<ITile>> colliders = {};
    std::shared_ptr<PA::Vector2i> firstPos = nullptr;
    std::shared_ptr<ITile> firstTile = nullptr;
    std::unordered_set<std::shared_ptr<ITile>> tilesPreviewSet = {};
    bool tilesCreation = false;
    bool waitForRelease = true;
    std::string tileName = "";
    void endTilesCreation();
    void tilesCreationUpdate();
    void placeTilesPreview();
    void triggerColliderRedirection(std::shared_ptr<ITile> tile);

    public:
    std::shared_ptr<ITile> getTile(PA::Vector2i index);
    void draw();
    void update();
    static std::shared_ptr<TileManager> getInstance();
    void createTiles(std::string tileName);
    std::shared_ptr<ITile> getCollider(PA::Vector2i index);

};

#endif