#include "Map.hpp"

namespace PA::Object::Map {

    void Map::update()
    {
        this->camera->update();
        this->roomManager.update();
        this->pnjManager.update();
        this->tileManager->update();
        PA::Object::Menu::AIcon::Action gameUIAction = this->gameUI.update();
        switch (gameUIAction) {
            case PA::Object::Menu::AIcon::Action::DELIVERIES:
                this->roomManager.createRoom("delivery");
                break;
            case PA::Object::Menu::AIcon::Action::WORKMAN:
                this->pnjManager.createPNJ("workman");
                break;
            case PA::Object::Menu::AIcon::Action::BRICK_WALL:
                this->tileManager->createTiles("brickWall");
                break;
            default:
                break;
        }
    }

    void Map::draw()
    {
        this->background.draw();
        this->roomManager.draw();
        this->pnjManager.draw();
        this->tileManager->draw();
        this->gameUI.draw();
    }
}
