#ifndef __OBJECT_WALL_ITile_HPP__
    #define __OBJECT_WALL_ITile_HPP__

    #include <string>
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Camera.hpp"

class PA::Object::Tile::ITile {
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
    virtual ~ITile() = default;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual bool isColliding() = 0;
    virtual void setColliding(bool collide) = 0;
    virtual void setPos(PA::Vector2i pos) = 0;
    virtual PA::Vector2i getPos() const = 0;
    virtual std::string getName() = 0;
    virtual void setStatus(PA::Lib::SDL2::Camera::Status status) = 0;
    virtual void setWallPosition(WallPosition position) = 0;
    virtual PA::Vector2i getWallPosition(WallPosition position) = 0;
};

#endif
