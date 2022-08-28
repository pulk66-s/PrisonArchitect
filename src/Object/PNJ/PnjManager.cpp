#include "PnjManager.hpp"

namespace PA::Object::PNJ {

    PnjManager::PnjManager()
    {
        for (int i = 0; i < 10; i++) {
            PA::Vector2<int> pos = {std::rand() % 1200, std::rand() % 900};
            this->pnjs->add(std::make_shared<PA::Object::PNJ::Workman>(pos));
        }
        this->validNames = {
            "workman",
        };
        this->images = {
            {
                "workman", std::make_shared<PA::Lib::SDL2::Graphic::Image>(
                    "res/sprites/pnj/workman.png",
                    PA::Vector2<int>{32, 32}, PA::Vector2<int>{0, 0}, 
                    true, PA::Vector2<int>{4, 4}, PA::Lib::SDL2::Camera::Status::FIXED
                )
            },
        };
        for (auto &image : this->images) {
            image.second->setIndex({0, 0});
        }
        this->event = PA::Lib::SDL2::Event::getInstance();
        this->camera = PA::Lib::SDL2::Camera::getInstance();
    }

    void PnjManager::addPnjToMap(std::string name)
    {
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> imageDim = this->images[name]->getDimensions();
        PA::Vector2<int> camPos = this->camera->getPos();
        mousePos -= PA::Vector2<int>{imageDim.x / 2, imageDim.y / 2};
        mousePos += camPos;
        if (name == "workman") {
            this->pnjs->add(std::make_shared<PA::Object::PNJ::Workman>(mousePos));
        }
    }

    void PnjManager::pnjCreationUpdate() {
        PA::Vector2<int> mousePos = this->event->getMousePosition();
        PA::Vector2<int> imageDim = this->currImage->getDimensions();
        mousePos -= PA::Vector2<int>{imageDim.x / 2, imageDim.y / 2};
        this->currImage->setPosition(mousePos);
        if (this->event->isClick()) {
            this->addPnjToMap(this->pnjName);
            this->waitForRelease = true;
        }
        if (this->event->isRightClick()) {
            this->pnjCreation = false;
        }
    }

    void PnjManager::update()
    {
        for (auto &pnj : *this->pnjs->getPnjs())
            pnj->update();
        if (this->waitForRelease) {
            if (this->event->isRelease()) {
                this->waitForRelease = false;
            } else {
                return;
            }
        }
        if (this->pnjCreation) {
            this->pnjCreationUpdate();
        }
    }

    void PnjManager::draw()
    {
        for (auto &pnj : *this->pnjs->getPnjs())
            pnj->draw();
        if (this->pnjCreation) {
            this->currImage->draw();
        }
    }

    void PnjManager::createPNJ(std::string name)
    {
        if (std::find(this->validNames.begin(), this->validNames.end(), name) == this->validNames.end())
            throw PA::Error::InvalidArgument("name is not valid", "PnjManager::createPNJ");
        this->pnjName = name;
        this->pnjCreation = true;
        this->currImage = this->images[name];
        this->waitForRelease = true;
    }

}