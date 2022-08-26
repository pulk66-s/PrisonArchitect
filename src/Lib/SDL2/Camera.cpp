#include "Camera.hpp"

namespace KA::Lib::SDL2 {

    Camera::Camera() {
        this->position = {0, 0};
        this->moveDirection = {0, 0};
        this->event = KA::Lib::SDL2::Event::getInstance();
    }
    
    KA::Vector2i Camera::getPos() {
        return (this->position);
    }
    
    std::shared_ptr<Camera> Camera::getInstance() {
        static std::shared_ptr<Camera> instance = std::make_shared<Camera>();
        return instance;
    }

    void Camera::setPos(KA::Vector2i pos) {
        this->position = pos;
    }

    void Camera::move(KA::Vector2i pos) {
        this->position.x += pos.x;
        this->position.y += pos.y;
    }

    void Camera::update() {
        if (this->event->isKeyPressed(SDL_SCANCODE_W)) {
            this->moveDirection.y = -1 * this->speed.y;
        } else if (this->event->isKeyReleased(SDL_SCANCODE_W)) {
            this->moveDirection.y = 0 * this->speed.y;
        }
        if (this->event->isKeyPressed(SDL_SCANCODE_S)) {
            this->moveDirection.y = 1 * this->speed.y;
        } else if (this->event->isKeyReleased(SDL_SCANCODE_S)) {
            this->moveDirection.y = 0 * this->speed.y;
        }
        if (this->event->isKeyPressed(SDL_SCANCODE_A)) {
            this->moveDirection.x = -1 * this->speed.x;
        } else if (this->event->isKeyReleased(SDL_SCANCODE_A)) {
            this->moveDirection.x = 0 * this->speed.x;
        }
        if (this->event->isKeyPressed(SDL_SCANCODE_D)) {
            this->moveDirection.x = 1 * this->speed.x;
        } else if (this->event->isKeyReleased(SDL_SCANCODE_D)) {
            this->moveDirection.x = 0 * this->speed.x;
        }
        this->position += this->moveDirection;
    }

}