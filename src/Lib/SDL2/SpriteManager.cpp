#include "SpriteManager.hpp"

namespace KA::Lib::SDL2 {

    SpriteManager::SpriteManager() {
        this->sprites = {};
    }

    SpriteManager::~SpriteManager() {
        for (auto &sprite : this->sprites) {
            SDL_FreeSurface(sprite.second);
        }
    }

    std::shared_ptr<SpriteManager> SpriteManager::getInstance() {
        static std::shared_ptr<SpriteManager> instance = std::make_shared<SpriteManager>();
        return (instance);
    }

    SDL_Surface *SpriteManager::getSprite(std::string path) {
        if (this->sprites.find(path) == this->sprites.end()) {
            this->sprites[path] = IMG_Load(path.c_str());
        }
        return (this->sprites[path]);
    }

}