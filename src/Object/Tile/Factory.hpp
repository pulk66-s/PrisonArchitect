#ifndef __OBJECT_WALL_TileFactory_HPP__
    #define __OBJECT_WALL_TileFactory_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/Wall/Brick.hpp"
    #include "Object/Tile/Wall/Preview.hpp"
    #include "Object/Tile/Room/Delivery.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Global/Vector.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <unordered_map>
    #include <memory>
    #include <functional>

#define CREATE_LAMBDA(className) [](PA::Vector2<int> index, PA::Vector2<int> pos) -> \
    std::shared_ptr<PA::Object::Tile::ITile> { \
        return (std::make_shared<className>(index, pos)); \
    }

class PA::Object::Tile::Factory {

    private:
    std::unordered_map<std::string, std::function<std::shared_ptr<PA::Object::Tile::ITile>(PA::Vector2<int> index, PA::Vector2<int> pos)>> lambdaMap;

    public:
    Factory();
    std::shared_ptr<PA::Object::Tile::ITile> create(std::string component, PA::Vector2<int> index = {0, 0}, PA::Vector2<int> pos = {0, 0});

};

#endif