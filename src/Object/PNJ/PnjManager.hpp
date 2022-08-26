#ifndef __OBJECT_PNJ_PnjManager_HPP__
    #define __OBJECT_PNJ_PnjManager_HPP__

    #include <vector>
    #include <string>
    #include <memory>
    #include <unordered_map>
    #include <algorithm>
    #include "Object/ObjectNamespace.hpp"
    #include "Pnj.hpp"
    #include "Workman.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Image.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Global/Error/InvalidArgument.hpp"

class PA::Object::PNJ::PnjManager {

    private:
    std::vector<std::shared_ptr<PA::Object::PNJ::Workman>> workers;
    std::shared_ptr<PA::Lib::SDL2::Camera> camera = nullptr;
    std::shared_ptr<PA::Lib::SDL2::Event> event = nullptr;
    bool waitForRelease = false;

    // PNJ creation
    std::string pnjName = "";
    bool pnjCreation = false;
    std::vector<std::string> validNames;
    std::unordered_map<std::string, std::shared_ptr<PA::Lib::SDL2::Graphic::Image>> images;
    std::unordered_map<std::string, PA::Vector2i> imagePos;
    std::shared_ptr<PA::Lib::SDL2::Graphic::Image> currImage;
    void pnjCreationUpdate();
    void addPnjToMap(std::string name);

    public:
    PnjManager();
    void update();
    void draw();
    void createPNJ(std::string name);

};

#endif