#ifndef __OBJECT_PNJ_IA_IA_HPP__
    #define __OBJECT_PNJ_IA_IA_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Map/Grid.hpp"
    #include "Object/Tile/TileManager.hpp"
    #include <ctime>
    #include <cstdlib>
    #include <unordered_map>

class PA::Object::PNJ::IA::Ia {

    public:
    enum Move {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    private:
    std::shared_ptr<Tile::TileManager> tileManager = Tile::TileManager::getInstance();
    unsigned int lastUpdateTime = SDL_GetTicks();
    PA::Object::PNJ::IA::Ia::Move currMove = PA::Object::PNJ::IA::Ia::Move::NONE;
    std::unordered_map<PA::Object::PNJ::IA::Ia::Move, PA::Vector2<int>> moveDirection;
    std::unordered_map<PA::Object::PNJ::IA::Ia::Move, int> moveSpriteSheetIndex;
    std::unique_ptr<PA::Vector2<int>> goToPos = nullptr;

    void idle(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant);
    void moveToGoTo(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant);

    protected:
    float moveTimeOffset = 0.1; // seconds
    PA::Vector2<int> speed = {1, 1};
    int moveOffset = 0;
    int maxMoveOffset = 10; 
    std::shared_ptr<PA::Object::Map::Grid> grid = PA::Object::Map::Grid::getInstance();

    public:
    Ia();
    void setGoToPos(PA::Vector2<int> pos);
    void update(PA::Vector2<int> *pos, std::shared_ptr<PA::Lib::SDL2::Graphic::SpriteSheet> spriteSheet, int currVariant);
    Move getMove();
};

#endif