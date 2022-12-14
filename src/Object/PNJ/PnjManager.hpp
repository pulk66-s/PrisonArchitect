#ifndef __OBJECT_PNJ_PnjManager_HPP__
    #define __OBJECT_PNJ_PnjManager_HPP__

    #include <vector>
    #include <string>
    #include <memory>
    #include <unordered_map>
    #include <algorithm>
    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Pnjs.hpp"
    #include "Object/PNJ/Workman.hpp"
    #include "Object/Items/Items.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Image.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Error/InvalidArgument.hpp"

class PA::Object::PNJ::PnjManager {

    private:
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = nullptr;
    std::shared_ptr<PA::Lib::SDL2::Event> event = nullptr;
    bool waitForRelease = false;
    std::shared_ptr<PNJ::Pnjs> pnjs = PNJ::Pnjs::getInstance();
    std::shared_ptr<Item::Items> items = Item::Items::getInstance();
    std::shared_ptr<Map::Grid> grid = Map::Grid::getInstance();

    // PNJ creation
    std::string pnjName = "";
    bool pnjCreation = false;
    std::vector<std::string> validNames;
    std::unordered_map<std::string, std::shared_ptr<PA::Lib::SDL2::Graphic::Image>> images;
    std::unordered_map<std::string, PA::Vector2<int>> imagePos;
    std::shared_ptr<PA::Lib::SDL2::Graphic::Image> currImage;
    void pnjCreationUpdate();
    void addPnjToMap(std::string name);
    void parseTaskAction(Task::ATask::Action action, std::shared_ptr<PNJ::Pnj> pnj);

    public:
    PnjManager();
    void update();
    void draw();
    void createPNJ(std::string name);

};

#endif