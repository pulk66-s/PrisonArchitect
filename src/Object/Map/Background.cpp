#include "Background.hpp"

namespace PA::Object::Map {
    Background::Background() {
        this->images = {
            {"dirt", CREATE_IMAGE}
        };
        this->spriteIndex = {
            {"dirt", PA::Vector2i{0, 0}}
        };
        for (auto &image : this->images) {
            image.second->setIndex(this->spriteIndex[image.first]);
        }
        for (int i = 0; i < this->dim.x; i++) {
            this->sprites[i] = {};
            for (int j = 0; j < this->dim.y; j++) {
                this->sprites[i][j] = std::make_shared<PA::Lib::SDL2::Graphic::Image>(*this->images["dirt"]);
                this->sprites[i][j]->setPosition({i * 30, j * 30});
            }
        }
    }

    void Background::draw() {
        this->sprites[0][0]->draw();
        for (int i = 0; i < this->dim.x; i++) {
            for (int j = 0; j < this->dim.y; j++) {
                this->sprites[i][j]->draw();
            }
        }
    }
}