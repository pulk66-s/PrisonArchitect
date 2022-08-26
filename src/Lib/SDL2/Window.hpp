#ifndef __LIB_SDL2_WINDOW_HPP__
    #define __LIB_SDL2_WINDOW_HPP__

    #include <SDL2/SDL.h>
    #include <memory>
    #include <iostream>
    #include "SDL2Namespace.hpp"
    #include "Window.hpp"

class KA::Lib::SDL2::Window {
    private:
    SDL_Window *window;

    public:
    Window(const char *title, int x, int y, int w, int h);
    ~Window();
    SDL_Window *get();
};

#endif