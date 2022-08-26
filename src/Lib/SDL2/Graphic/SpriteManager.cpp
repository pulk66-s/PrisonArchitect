#include "SpriteManager.hpp"

namespace PA::Lib::SDL2::Graphic {

    SpriteManager::SpriteManager() {
        this->sprites = {};
    }

    std::shared_ptr<SpriteManager> SpriteManager::getInstance() {
        static std::shared_ptr<SpriteManager> instance = std::make_shared<SpriteManager>();
        return (instance);
    }

    std::shared_ptr<PA::Lib::SDL2::Graphic::Surface> SpriteManager::getSprite(std::string path) {
        if (this->sprites.find(path) == this->sprites.end()) {
            this->sprites[path] = std::make_shared<Surface>(path);
        }
        return (this->sprites[path]);
    }

}