#include "Event.hpp"

namespace PA::Lib::SDL2 {

    Event::Event() {
        this->event = SDL_Event();
        this->isQuitEvent = false;
    }

    void Event::poll() {
        SDL_PollEvent(&this->event);
        if (this->event.type == SDL_QUIT) {
            this->isQuitEvent = true;
        }
        if (this->event.type == SDL_MOUSEBUTTONDOWN) {
            this->isClickEvent = true;
            this->clickPosition = {this->event.button.x, this->event.button.y};
        } else {
            this->isClickEvent = false;
        }
    }

    bool Event::isQuit() {
        return (this->isQuitEvent);
    }

    bool Event::isClick() {
        return (this->isClickEvent);
    }

    PA::Vector2i Event::getClickPosition() {
        return (this->clickPosition);
    }

    std::shared_ptr<PA::Lib::SDL2::Event> Event::getInstance() {
        static std::shared_ptr<PA::Lib::SDL2::Event> instance = std::make_shared<PA::Lib::SDL2::Event>();
        return (instance);
    }

    PA::Vector2i Event::getMousePosition() {
        int x, y;
        SDL_GetMouseState(&x, &y);
        return (PA::Vector2i{x, y});
    }

    bool Event::isRelease() {
        return (this->event.type == SDL_MOUSEBUTTONUP);
    }

    bool Event::isKeyPressed(SDL_Scancode key) {
        return (this->event.type == SDL_KEYDOWN && this->event.key.keysym.scancode == key);
    }

    bool Event::isKeyReleased(SDL_Scancode key) {
        return (this->event.type == SDL_KEYUP && this->event.key.keysym.scancode == key);
    }

    bool Event::isRightClick() {
        return (this->event.type == SDL_MOUSEBUTTONDOWN && this->event.button.button == SDL_BUTTON_RIGHT);
    }

}