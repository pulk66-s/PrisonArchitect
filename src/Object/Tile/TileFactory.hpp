#ifndef __OBJECT_WALL_TileFactory_HPP__
    #define __OBJECT_WALL_TileFactory_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/BrickWall.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Global/Vector.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include <unordered_map>
    #include <memory>
    #include <functional>

#define CREATE_LAMBDA(className) [](KA::Vector2i index,KA::Vector2i pos) -> \
    std::shared_ptr<KA::Object::Tile::ITile> { \
        return (std::make_shared<className>(index, pos)); \
    }

class KA::Object::Tile::Factory {

    private:
    std::unordered_map<std::string, std::function<std::shared_ptr<KA::Object::Tile::ITile>(KA::Vector2i index, KA::Vector2i pos)>> lambdaMap;

    public:
    Factory();
    std::shared_ptr<KA::Object::Tile::ITile> create(std::string component, KA::Vector2i pos, KA::Vector2i index);

};

#endif