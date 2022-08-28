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
    std::shared_ptr<PA::Object::Tile::TileManager> tileManager = PA::Object::Tile::TileManager::getInstance();
    PA::Object::PNJ::Task::Tasks tasks;

    std::unique_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet;
    unsigned short nb_variant, curr_variant = 0;
    PA::Vector2<int> spriteIndex;
    PA::Vector2<int> pos;
    std::unordered_map<PA::Object::PNJ::IA::Ia::Move, PA::Vector2<int>> moveDirection;
    std::unordered_map<PA::Object::PNJ::IA::Ia::Move, int> moveSpriteSheetIndex;

    // IA
    std::unique_ptr<PA::Object::PNJ::IA::Ia> ia = nullptr;
    unsigned int lastUpdateTime = SDL_GetTicks();
    float moveTimeOffset = 0.1; // seconds
    PA::Vector2<int> speed = {1, 1};
    PA::Object::PNJ::IA::Ia::Move currMove = PA::Object::PNJ::IA::Ia::Move::NONE;
    int moveOffset = 0;
    int maxMoveOffset = 10;

    public:
    Pnj(std::string path, PA::Vector2<int> pos={0, 0}, unsigned short variant=1);
    virtual ~Pnj();
    void draw();
    void update();
    int getNbTask() const;
    void addTask(std::shared_ptr<Task::ATask> task);

};

#endif
