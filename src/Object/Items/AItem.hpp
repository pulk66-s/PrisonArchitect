#ifndef __PA_ITEMS_AITEM_HPP__
    #define __PA_ITEMS_AITEM_HPP__

    #include "Object/Items/AItem.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include "Object/Map/Grid.hpp"
    #include <string>
    #include <memory>

class PA::Object::Item::AItem {

    protected:
    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet = nullptr;
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();

    std::string name = "";
    bool free = true;

    public:
    AItem(std::string name);
    AItem(const AItem& item);
    void draw();
    void update();
    void setSpriteSheet(std::string path, PA::Vector2<int> nbSprite);
    void setPos(PA::Vector2<int> pos);
    void setFree(bool free);
    bool isFree() const;
    PA::Vector2<int> getPos();

};

#endif