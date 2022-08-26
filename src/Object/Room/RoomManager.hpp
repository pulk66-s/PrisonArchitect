#ifndef __OBJECT_ROOM_ROOMMANAGER_HPP__
    #define __OBJECT_ROOM_ROOMMANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Room/Delivery.hpp"
    #include "Object/Room/ARoom.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Global/Vector.hpp"
    #include <vector>
    #include <map>
    #include <memory>

class KA::Object::Room::RoomManager {

    private:
    std::map<std::string, std::vector<std::shared_ptr<KA::Object::Room::ARoom>>> rooms;
    std::shared_ptr<KA::Lib::SDL2::Event> event;
    std::shared_ptr<KA::Lib::SDL2::Camera> camera;

    // room creation
    bool roomCreation = false;
    std::unique_ptr<KA::Lib::SDL2::Shape::Rectangle> roomCreationRect;
    std::shared_ptr<KA::Object::Grid> grid = nullptr;
    std::unique_ptr<KA::Vector2i> roomCreationFirstPoint = nullptr;
    std::string roomCreationName;
    bool waitingForRelease = false;
    KA::Vector2i roomCreationRectDim;

    void roomCreationUpdate();

    public:
    RoomManager();
    void draw();
    void update();
    void createRoom(std::string name);
    // Create room by name and return
    std::shared_ptr<KA::Object::Room::ARoom> createRoom(std::string name, KA::Vector2i dim, KA::Vector2i pos);

};

#endif