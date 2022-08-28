#ifndef __PA_OBJECT_TILE_ROOM_MANAGER_HPP__
    #define __PA_OBJECT_TILE_ROOM_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Factory.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/NullPtr.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include <memory>
    #include <map>

class PA::Object::Tile::Room::Manager {

    private:
    std::shared_ptr<PA::Lib::SDL2::Event> event = PA::Lib::SDL2::Event::getInstance();
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = PA::Lib::SDL2::Camera::getInstance();
    std::map<PA::Vector2i, std::shared_ptr<ITile>> *tiles;
    Tile::Factory tileFactory;

    bool roomCreation = false;
    bool waitForRelease = false;
    std::unique_ptr<PA::Lib::SDL2::Shape::Rectangle> roomCreationRect = nullptr;
    std::unique_ptr<PA::Vector2i> firstPos = nullptr;
    std::shared_ptr<ITile> tile = nullptr;

    void roomCreationUpdate();
    void endCreation();
    void addRoomToGrid(PA::Vector2i pos, PA::Vector2i dim);

    public:
    Manager(std::map<PA::Vector2i, std::shared_ptr<ITile>> *tiles);
    void update();
    void draw();
    void createRoom(std::shared_ptr<ITile> tile);
    std::vector<PA::Vector2i> getRoomPos(std::string name);
    static std::shared_ptr<Manager> create(std::map<PA::Vector2i, std::shared_ptr<ITile>> *tiles = nullptr);
    static std::shared_ptr<Manager> getInstance();

};

#endif