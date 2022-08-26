#include "Window.hpp"

namespace KA::Lib::SDL2 {

    Window::Window(const char* title, int x, int y, int w, int h)
    {
        this->window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
        if (this->window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    Window::~Window()
    {
        SDL_DestroyWindow(this->window);
    }

    SDL_Window *Window::get()
    {
        return (this->window);
    }

};