#ifndef __OBJECT_WALL_ITile_HPP__
    #define __OBJECT_WALL_ITile_HPP__

    #include <string>
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Camera.hpp"

class PA::Object::Tile::ITile {
    public:
    virtual ~ITile() = default;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual bool isColliding() = 0;
    virtual void setColliding(bool collide) = 0;
    virtual void setPos(PA::Vector2<int> pos) = 0;
    virtual PA::Vector2<int> getPos() const = 0;
    virtual std::string getName() const = 0;
    virtual int getPrice() const = 0;
};

#endif
