#include "main.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    try {
        std::srand(std::time(nullptr));
        KA::Lib::SDL2::LSDL2 sdl2;
        KA::Lib::SDL2::Window window("Hello World!", 100, 100, 1200, 900);
        int index = -1;
        Uint32 flags = SDL_RENDERER_ACCELERATED;
        std::shared_ptr<KA::Lib::SDL2::Renderer> renderer = KA::Lib::SDL2::Renderer::create(&window, &index, &flags);
        std::shared_ptr<KA::Lib::SDL2::Event> event = KA::Lib::SDL2::Event::getInstance();
        KA::Object::Map map;

        while (!event->isQuit()) {
            renderer->clear(0, 0, 0, 255);
            event->poll();
            map.update();
            map.draw();
            renderer->render();
        }
        return (0);
    } catch (KA::Error::InvalidArgument &e) {
        std::cerr << "Error: " << e.type() << " " <<  e.what() << " " << e.where() << std::endl;
        return (1);
    }
}
