#ifndef __OBJECT_MAP_HPP__
    #define __OBJECT_MAP_HPP__

    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Vector.hpp"
    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/PnjManager.hpp"
    #include "Object/Tile/TileManager.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Map/Background.hpp"
    #include "Object/Room/RoomManager.hpp"
    #include "Object/Menu/GameUI.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/TileFactory.hpp"
    #include <unordered_map>
    #include <map>
    #include <memory>

class PA::Object::Map::Map {

    private:
    std::shared_ptr<PA::Object::Tile::TileManager> tileManager;
    PA::Object::PNJ::PnjManager pnjManager;
    std::shared_ptr<PA::Object::Map::Grid> grid;
    PA::Object::Room::RoomManager roomManager;
    PA::Object::Menu::GameUI gameUI;
    PA::Object::Map::Background background;
    std::shared_ptr<PA::Lib::SDL2::Camera> camera;

    public:
    Map();
    void update();
    void draw();

};

#endif