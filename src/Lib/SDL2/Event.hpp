#ifndef __LIB_SDL2_EVENT_HPP__
    #define __LIB_SDL2_EVENT_HPP__

    #include "Lib/SDL2/SDL2Namespace.hpp"
    #include "Global/Vector.hpp"
    #include <SDL2/SDL.h>
    #include <memory>

class PA::Lib::SDL2::Event {
    private:
    SDL_Event event;
    bool isQuitEvent = false;
    bool isClickEvent = false;
    PA::Vector2i clickPosition = {0, 0};

    public:
    Event();
    void poll();
    bool isQuit();
    bool isClick();
    bool isRightClick();
    bool isRelease();
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    PA::Vector2i getClickPosition();
    PA::Vector2i getMousePosition();
    static std::shared_ptr<PA::Lib::SDL2::Event> getInstance();
};

#endif