#include "SDL2.hpp"

namespace PA::Lib::SDL2 {

    LSDL2::LSDL2()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        if(TTF_Init() == -1){
            std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
            exit(1);
        }
    }
    
    LSDL2::~LSDL2()
    {
        TTF_Quit();
        SDL_Quit();
    }
}
