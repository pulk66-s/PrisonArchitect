#ifndef __PA_OBJCET_TILE_WALL_PREVIEW_HPP__
    #define __PA_OBJCET_TILE_WALL_PREVIEW_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/Wall/AWall.hpp"
    #include "Global/Vector.hpp"

class PA::Object::Tile::Wall::Preview : public PA::Object::Tile::Wall::AWall
{
    private:
    std::string buildWall = "";

    public:
    Preview(PA::Vector2<int> index, PA::Vector2<int> pos);
    Preview(Preview *preview);
    void setBuildWall(std::string wall);
    std::string getBuildWall() const;
    using AWall::draw;

};

#endif