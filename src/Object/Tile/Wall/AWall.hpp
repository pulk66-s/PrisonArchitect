#ifndef __PA_OBJECT_TILE_WALL_AWALL_HPP__
    #define __PA_OBJECT_TILE_WALL_AWALL_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ATile.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include "Lib/SDL2/Camera.hpp"
    #include <memory>
    #include <unordered_map>

class PA::Object::Tile::Wall::AWall : public PA::Object::Tile::ATile {

    public:
    enum WallPosition {
        CROSS,
        CORNER_UPPER_LEFT,
        CORNER_UPPER_RIGHT,
        CORNER_LOWER_LEFT,
        CORNER_LOWER_RIGHT,
        COLUMN,
        LINE,
        LEFT,
        RIGHT,
        UP,
        DOWN,
        TRI_DOWN,
        TRI_UP,
        TRI_LEFT,
        TRI_RIGHT,
    };

    protected:
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet = nullptr;
    std::unordered_map<WallPosition, PA::Vector2<int>> wallPositions = {};
    std::string item = "";
    std::string task = "";
    bool wantRedirection = false;

    public:
    AWall();
    AWall(AWall *other);
    void setWallPosition(WallPosition position);
    void setPos(PA::Vector2<int> position);
    PA::Vector2<int> getPos() const;
    void setStatus(PA::Lib::SDL2::Camera::Status status);
    void draw();
    PA::Vector2<int> getWallPosition(WallPosition position);
    bool operator<(const AWall& other) const;
    void update();
    void createSpriteSheet(PA::Vector2<int> pos, PA::Vector2<int> index);
    std::string getItem();
    std::string getTask();
    bool getWantRedirection() const;
    void setWantRedirection(bool wantRedirection);

};

#endif