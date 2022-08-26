#ifndef __LIB_SDL2_RENDERER_HPP__
    #define __LIB_SDL2_RENDERER_HPP__

    #include "SDL2Namespace.hpp"
    #include "Window.hpp"
    #include <SDL2/SDL.h>
    #include <iostream>

class KA::Lib::SDL2::Renderer {
    private:
    SDL_Renderer *renderer;

    public:
    Renderer(KA::Lib::SDL2::Window &window, int index, Uint32 flags);
    ~Renderer();
    SDL_Renderer *get();
    void render();
    bool clear(int r, int g, int b, int a);
    static std::shared_ptr<KA::Lib::SDL2::Renderer> create(KA::Lib::SDL2::Window *window, int *index, Uint32 *flags);
    static std::shared_ptr<KA::Lib::SDL2::Renderer> getInstance();
};

#endif