#ifndef __OBJECT_PNJ_PNJ_HPP__
    #define __OBJECT_PNJ_PNJ_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/ITile.hpp"
    #include "Object/Tile/TileManager.hpp"
    #include "Object/PNJ/Tasks/Tasks.hpp"
    #include "Object/PNJ/IPnj.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include "Global/Vector.hpp"
    #include "IA/Workman.hpp"
    #include <string>
    #include <memory>
    #include <unordered_map>

class PA::Object::PNJ::Pnj : public PA::Object::PNJ::IPnj {
    protected:
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();
    PA::Object::PNJ::Task::Tasks tasks;

    std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet;
    int nb_variant, currVariant = 0;
    PA::Vector2<int> spriteIndex;
    PA::Vector2<int> pos;

    std::unique_ptr<PA::Object::PNJ::IA::Ia> ia = nullptr;
    void iaUpdate();

    public:
    Pnj(std::string path, PA::Vector2<int> pos={0, 0}, int variant=1);
    virtual ~Pnj();
    void draw();
    void update();
    int getNbTask() const;
    void addTask(std::shared_ptr<Task::ATask> task);

};

#endif
