#include "Object/Menu/Notif/Errors.hpp"

namespace PA::Object::Menu::Notif {

    void Errors::addError(std::string message) {
        int errorSize = this->errors.size();
        PA::Vector2i rectPos = this->pos;
        rectPos.y += errorSize * (textDim.y + buff.y);
        this->errors.push_back(Error(message, this->pos, this->textDim));
    }

    void Errors::draw() {
        for (auto& error : this->errors) {
            error.draw();
        }
    }

    void Errors::update() {
        for (auto& error : this->errors) {
            error.update();
        }
        if (this->errors.size() > 0) {
            this->errors.erase(
                std::remove_if(
                    this->errors.begin(), this->errors.end(),
                    [](const Error& error) {
                        return (error.isDone());
                    }
                ),
                this->errors.end()
            );
        }
        int index = 0;
        for (auto& error : this->errors) {
            error.setPos(this->pos + PA::Vector2i(0, index * (this->textDim.y + this->buff.y)));
            index++;
        }
    }

}