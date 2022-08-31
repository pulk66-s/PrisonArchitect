#include "Object/Tile/Tiles.hpp"

namespace PA::Object::Tile {

    Tiles::Tiles() {
        this->tiles = std::make_shared<std::map<PA::Vector2<int>, std::shared_ptr<ATile>>>();
    }

    std::shared_ptr<Tiles> Tiles::getInstance()
    {
        static std::shared_ptr<Tiles> instance = std::make_shared<Tiles>();
        return (instance);
    }

    void Tiles::addTile(PA::Vector2<int> pos, std::shared_ptr<ATile> tile)
    {
        (*this->tiles)[pos] = tile;
    }

    std::shared_ptr<std::map<PA::Vector2<int>, std::shared_ptr<ATile>>> Tiles::get()
    {
        return (this->tiles);
    }

    std::shared_ptr<ATile> Tiles::get(PA::Vector2<int> index)
    {
        if (this->tiles->find(index) != this->tiles->end()) {
            return ((*this->tiles)[index]);
        }
        return (nullptr);
    }

}