#include "Object/Menu/Notif/Notifs.hpp"

namespace PA::Object::Menu::Notif {

    void Notifs::addError(std::string message) {
        int notifSize = this->notifs.size();
        PA::Vector2i rectPos = this->pos;
        rectPos.y += notifSize * (textDim.y + buff.y);
        this->notifs.push_back(Error(message, this->pos, this->textDim));
    }

    void Notifs::addSuccess(std::string message) {
        int notifSize = this->notifs.size();
        PA::Vector2i rectPos = this->pos;
        rectPos.y += notifSize * (textDim.y + buff.y);
        this->notifs.push_back(Success(message, this->pos, this->textDim));
    }

    void Notifs::draw() {
        for (auto& notif : this->notifs) {
            notif.draw();
        }
    }

    void Notifs::update() {
        for (auto& notif : this->notifs) {
            notif.update();
        }
        if (this->notifs.size() > 0) {
            this->notifs.erase(
                std::remove_if(
                    this->notifs.begin(), this->notifs.end(),
                    [](const ANotif& notif) {
                        return (notif.isDone());
                    }
                ),
                this->notifs.end()
            );
        }
        int index = 0;
        for (auto& notif : this->notifs) {
            notif.setPos(this->pos + PA::Vector2i(0, index * (this->textDim.y + this->buff.y)));
            index++;
        }
    }

}