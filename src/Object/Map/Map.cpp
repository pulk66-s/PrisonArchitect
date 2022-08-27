#include "Map.hpp"

namespace PA::Object::Map {

    void Map::update()
    {
        try {
            this->camera->update();
            this->pnjManager.update();
            this->tileManager->update();
            PA::Object::Menu::AIcon::Action gameUIAction = this->gameUI.update();
            switch (gameUIAction) {
                case PA::Object::Menu::AIcon::Action::DELIVERIES:
                    this->tileManager->createTiles("delivery");
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
        } catch (PA::Error::NotEnoughMoney &e) {
            this->gameUI.addError(e.what());
        } catch (PA::Error::NotifSuccess &e) {
            this->gameUI.addSuccess(e.what());
        } catch (PA::Error::InvalidArgument &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Map::draw()
    {
        this->background.draw();
        this->pnjManager.draw();
        this->tileManager->draw();
        this->gameUI.draw();
    }
}
