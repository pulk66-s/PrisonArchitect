#ifndef __LIB_SDL2_EVENT_HPP__
    #define __LIB_SDL2_EVENT_HPP__

    #include "SDL2Namespace.hpp"
    #include "Global/Vector.hpp"
    #include <SDL2/SDL.h>
    #include <memory>

class KA::Lib::SDL2::Event {
    private:
    SDL_Event event;
    bool isQuitEvent = false;
    bool isClickEvent = false;
    KA::Vector2i clickPosition = {0, 0};

    public:
    Event();
    void poll();
    bool isQuit();
    bool isClick();
    bool isRightClick();
    bool isRelease();
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    KA::Vector2i getClickPosition();
    KA::Vector2i getMousePosition();
    static std::shared_ptr<KA::Lib::SDL2::Event> getInstance();
};

#endif