#include "ARoom.hpp"

namespace PA::Object::Room {

    ARoom::ARoom(PA::Vector2i dim, PA::Vector2i pos, std::string name) {
        this->name = name;
        this->dim = dim;
        this->pos = pos;
        for (int i = 0; i < dim.x; i++) {
            for (int j = 0; j < dim.y; j++) {
                PA::Vector2i subPos = {i * this->gridDim.x + this->pos.x * this->gridDim.x, j * this->gridDim.y + this->pos.y * this->gridDim.y};
                PA::Vector2i subDim = {this->gridDim.x / 2, this->gridDim.y / 2};
                this->rectangles.push_back(PA::Lib::SDL2::Shape::Rectangle(
                    subPos, subDim, {150, 150, 150, 0}, true
                ));
                subPos.x += subDim.x;
                subPos.y += subDim.y;
                this->rectangles.push_back(PA::Lib::SDL2::Shape::Rectangle(
                    subPos, subDim, {150, 150, 150, 0}, true
                ));
            }
        }
        PA::Vector2i textDim = {this->gridDim.x * (this->dim.x > 10 ? 10 : this->dim.x), (this->dim.y > 15 ? this->gridDim.y * this->dim.y * 0.1 : this->gridDim.y * 2)};
        PA::Vector2i textPos = {this->pos.x * this->gridDim.x, this->pos.y * this->gridDim.y + this->gridDim.y * this->dim.y - textDim.y};
        if (this->dim.x > 10) {
            textPos.x += (this->gridDim.x * (this->dim.x - 10)) / 2;
        }
        this->text = std::make_unique<PA::Lib::SDL2::Graphic::Text>(
            this->name,
            textPos,
            textDim
        );
    }

    void ARoom::draw() {
        for (auto &rectangle : this->rectangles) {
            rectangle.draw();
        }
        this->text->draw();
    }

}