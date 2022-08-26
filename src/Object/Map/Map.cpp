#include "Map.hpp"

namespace KA::Object {
    Map::Map()
    {
        this->grid = KA::Object::Grid::getInstance();
        this->camera = KA::Lib::SDL2::Camera::getInstance();
        this->tileManager = KA::Object::TileManager::getInstance();
    }

    void Map::update()
    {
        this->camera->update();
        KA::Object::Grid::Action gridAction = this->grid->update();
        if (gridAction != KA::Object::Grid::Action::NONE) {
            this->tileManager->createTiles(gridAction);
        }
        this->roomManager.update();
        this->pnjManager.update();
        KA::Object::Menu::AIcon::Action gameUIAction = this->gameUI.update();
        switch (gameUIAction) {
            case KA::Object::Menu::AIcon::Action::DELIVERIES:
                this->roomManager.createRoom("delivery");
                break;
            case KA::Object::Menu::AIcon::Action::WORKMAN:
                this->pnjManager.createPNJ("workman");
                break;
            case KA::Object::Menu::AIcon::Action::BRICK_WALL:
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
