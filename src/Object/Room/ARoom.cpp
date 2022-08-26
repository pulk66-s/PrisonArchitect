#include "ARoom.hpp"

namespace KA::Object::Room {

    ARoom::ARoom(KA::Vector2i dim, KA::Vector2i pos, std::string name) {
        this->name = name;
        this->dim = dim;
        this->pos = pos;
        for (int i = 0; i < dim.x; i++) {
            for (int j = 0; j < dim.y; j++) {
                KA::Vector2i subPos = {i * this->gridDim.x + this->pos.x * this->gridDim.x, j * this->gridDim.y + this->pos.y * this->gridDim.y};
                KA::Vector2i subDim = {this->gridDim.x / 2, this->gridDim.y / 2};
                this->rectangles.push_back(KA::Lib::SDL2::Shape::Rectangle(
                    subPos, subDim, {150, 150, 150, 0}, true
                ));
                subPos.x += subDim.x;
                subPos.y += subDim.y;
                this->rectangles.push_back(KA::Lib::SDL2::Shape::Rectangle(
                    subPos, subDim, {150, 150, 150, 0}, true
                ));
            }
        }
        KA::Vector2i textDim = {this->gridDim.x * (this->dim.x > 10 ? 10 : this->dim.x), (this->dim.y > 15 ? this->gridDim.y * this->dim.y * 0.1 : this->gridDim.y * 2)};
        KA::Vector2i textPos = {this->pos.x * this->gridDim.x, this->pos.y * this->gridDim.y + this->gridDim.y * this->dim.y - textDim.y};
        if (this->dim.x > 10) {
            textPos.x += (this->gridDim.x * (this->dim.x - 10)) / 2;
        }
        this->text = std::make_unique<KA::Lib::SDL2::Text>(
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