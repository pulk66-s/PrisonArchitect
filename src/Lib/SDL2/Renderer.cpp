#include "Lib/SDL2/Renderer.hpp"

namespace PA::Lib::SDL2 {
    
    Renderer::Renderer(PA::Lib::SDL2::Window &window, int index, Uint32 flags)
    {
        this->renderer = SDL_CreateRenderer(window.get(), index, flags);
        SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
        if (this->renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }
    
    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(this->renderer);
    }

    SDL_Renderer *Renderer::getRenderer()
    {
        return (this->renderer);
    }

    void Renderer::render()
    {
        SDL_RenderPresent(this->renderer);
    }

    bool Renderer::clear(int r, int g, int b, int a)
    {
        if (SDL_SetRenderDrawColor(this->renderer, r, g, b, a) != 0) {
            std::cerr << "SDL_SetRenderDrawColor Error: " << SDL_GetError() << std::endl;
            return (false);
        }
        return (SDL_RenderClear(this->renderer) == 0);
    }

    std::shared_ptr<PA::Lib::SDL2::Renderer> Renderer::create(PA::Lib::SDL2::Window *window, int *index, Uint32 *flags)
    {
        static std::shared_ptr<PA::Lib::SDL2::Renderer> instance = std::make_shared<PA::Lib::SDL2::Renderer>(*window, *index, *flags);
        return (instance);
    }

    std::shared_ptr<PA::Lib::SDL2::Renderer> Renderer::getInstance()
    {
        return (PA::Lib::SDL2::Renderer::create(NULL, NULL, NULL));
    }
}
