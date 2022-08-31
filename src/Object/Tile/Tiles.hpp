#ifndef __PA_OBJECT_TILE_TILES_HPP__
    #define __PA_OBJECT_TILE_TILES_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Tile/ATile.hpp"
    #include "Object/Tile/Wall/Preview.hpp"
    #include "Global/Vector.hpp"
    #include <map>
    #include <memory>
    #include <functional>

class PA::Object::Tile::Tiles {

    private:
    std::shared_ptr<std::map<PA::Vector2<int>, std::shared_ptr<ATile>>> tiles;

    public:
    Tiles();
    void addTile(PA::Vector2<int> pos, std::shared_ptr<ATile> tile);
    static std::shared_ptr<Tiles> getInstance();
    std::shared_ptr<std::map<PA::Vector2<int>, std::shared_ptr<ATile>>> get();
    std::shared_ptr<ATile> get(PA::Vector2<int> index);
    std::shared_ptr<ATile> get(std::function<bool(std::shared_ptr<ATile>)> cond);

};

#endif