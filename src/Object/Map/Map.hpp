#ifndef __OBJECT_MAP_HPP__
    #define __OBJECT_MAP_HPP__

    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Vector.hpp"
    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/PnjManager.hpp"
    #include "Object/Map/TileManager.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Map/Background.hpp"
    #include "Object/Room/RoomManager.hpp"
    #include "Object/Menu/GameUI.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/TileFactory.hpp"
    #include <unordered_map>
    #include <map>
    #include <memory>

class KA::Object::Map {

    private:
    std::shared_ptr<KA::Object::TileManager> tileManager;
    KA::Object::PNJ::PnjManager pnjManager;
    std::shared_ptr<KA::Object::Grid> grid;
    KA::Object::Room::RoomManager roomManager;
    KA::Object::Menu::GameUI gameUI;
    KA::Object::Background background;
    std::shared_ptr<KA::Lib::SDL2::Camera> camera;

    public:
    Map();
    void update();
    void draw();

};

#endif