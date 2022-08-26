#include "PnjManager.hpp"

namespace KA::Object::PNJ {

    PnjManager::PnjManager()
    {
        for (int i = 0; i < 10; i++) {
            KA::Vector2i pos = {std::rand() % 1200, std::rand() % 900};
            this->workers.push_back(std::make_shared<KA::Object::PNJ::Workman>(pos));
        }
        this->validNames = {
            "workman",
        };
        this->images = {
            {
                "workman", std::make_shared<KA::Lib::SDL2::Image>(
                    "res/sprites/pnj/workman.png",
                    KA::Vector2i{32, 32}, KA::Vector2i{0, 0}, 
                    true, KA::Vector2i{4, 4}, KA::Lib::SDL2::Camera::Status::FIXED
                )
            },
        };
        for (auto &image : this->images) {
            image.second->setIndex({0, 0});
        }
        this->event = KA::Lib::SDL2::Event::getInstance();
        this->camera = KA::Lib::SDL2::Camera::getInstance();
    }

    void PnjManager::addPnjToMap(std::string name)
    {
        KA::Vector2i mousePos = this->event->getMousePosition();
        KA::Vector2i imageDim = this->images[name]->getDimensions();
        KA::Vector2i camPos = this->camera->getPos();
        mousePos -= KA::Vector2i{imageDim.x / 2, imageDim.y / 2};
        mousePos += camPos;
        if (name == "workman") {
            this->workers.push_back(std::make_shared<KA::Object::PNJ::Workman>(mousePos));
        }
    }

    void PnjManager::pnjCreationUpdate() {
        KA::Vector2i mousePos = this->event->getMousePosition();
        KA::Vector2i imageDim = this->currImage->getDimensions();
        mousePos -= KA::Vector2i{imageDim.x / 2, imageDim.y / 2};
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
        for (auto &worker : this->workers)
            worker->update();
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
        for (auto &worker : this->workers)
            worker->draw();
        if (this->pnjCreation) {
            this->currImage->draw();
        }
    }

    void PnjManager::createPNJ(std::string name)
    {
        if (std::find(this->validNames.begin(), this->validNames.end(), name) == this->validNames.end())
            throw KA::Error::InvalidArgument("name is not valid", "PnjManager::createPNJ");
        this->pnjName = name;
        this->pnjCreation = true;
        this->currImage = this->images[name];
        this->waitForRelease = true;
    }

}