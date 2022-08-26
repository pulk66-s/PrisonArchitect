#include "Map.hpp"

namespace PA::Object::Map {
    Map::Map()
    {
        this->grid = PA::Object::Map::Grid::getInstance();
        this->camera = PA::Lib::SDL2::Camera::getInstance();
        this->tileManager = PA::Object::Tile::TileManager::getInstance();
    }

    void Map::update()
    {
        this->camera->update();
        PA::Object::Map::Grid::Action gridAction = this->grid->update();
        if (gridAction != PA::Object::Map::Grid::Action::NONE) {
            this->tileManager->createTiles(gridAction);
        }
        this->roomManager.update();
        this->pnjManager.update();
        PA::Object::Menu::AIcon::Action gameUIAction = this->gameUI.update();
        switch (gameUIAction) {
            case PA::Object::Menu::AIcon::Action::DELIVERIES:
                this->roomManager.createRoom("delivery");
                break;
            case PA::Object::Menu::AIcon::Action::WORKMAN:
                this->pnjManager.createPNJ("workman");
                break;
            case PA::Object::Menu::AIcon::Action::BRICK_WALL:
                this->grid->createWall("brickWall");
                break;
            default:
                break;
        }
    }

    void Map::draw()
    {
        this->background.draw();
        this->roomManager.draw();
        this->grid->draw();
        this->pnjManager.draw();
        this->tileManager->draw();
        this->gameUI.draw();
    }
}
