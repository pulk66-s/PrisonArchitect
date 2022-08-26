#ifndef __OBJECT_GRID_HPP__
    #define __OBJECT_GRID_HPP__

    #include "Lib/SDL2/Shape/Rectangle.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include "Lib/SDL2/Event.hpp"
    #include "Lib/SDL2/Image.hpp"   
    #include "Global/Error/InvalidArgument.hpp"
    #include "Global/Vector.hpp"
    #include "Object/ObjectNamespace.hpp"
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <unordered_map>

class KA::Object::Grid {

    public:
    enum Action {
        CREATE_BRICK_WALL,
        NONE
    };

    private:
    std::vector<std::vector<std::string>> grid;
    int width, height;
    KA::Vector2i dimension;
    KA::Vector2i squareDim;
    std::vector<KA::Lib::SDL2::Shape::Rectangle> rectangles;
    std::shared_ptr<KA::Lib::SDL2::Camera> camera;
    std::shared_ptr<KA::Lib::SDL2::Event> event;
    bool waitForRelease = false;


    // Wall Creation
    public:
    enum WallDirection {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT,
        SINGLE_UP,
        SINGLE_DOWN,
        SINGLE_LEFT,
        SINGLE_RIGHT,
    };
    struct WallInfo {
        KA::Vector2i pos;
        KA::Vector2i index;
    };
    private:
    std::unordered_map<std::string, Action> wallActions;
    std::vector<std::string> allowedWalls;
    std::string wallCreationName = "";
    bool wallCreation = false;
    std::unique_ptr<KA::Vector2i> firstWallPos = nullptr;
    std::unordered_map<std::string, std::shared_ptr<KA::Lib::SDL2::Image>> images;
    std::unordered_map<std::string, std::unordered_map<WallDirection, KA::Vector2i>> imageIndex;
    std::shared_ptr<KA::Lib::SDL2::Image> wallImage;
    std::vector<std::shared_ptr<KA::Lib::SDL2::Image>> wallPreviews = {};
    Action wallCreationUpdate();
    void setWallIndex(std::shared_ptr<KA::Lib::SDL2::Image> &wall, KA::Vector2i starting, KA::Vector2i ending);
    void addWallToPreview(KA::Vector2i pos);
    std::vector<WallInfo> wallInfos = {};

    public:
    Grid();
    Action update();
    void draw();
    KA::Vector2i getDim();
    KA::Vector2i transformPos(KA::Vector2i pos);
    void createWall(std::string type);
    std::vector<WallInfo> getWallsInfo();
    static std::shared_ptr<Grid> getInstance();

};

#endif