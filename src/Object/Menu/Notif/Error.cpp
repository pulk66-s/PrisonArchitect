#include "Object/Menu/Notif/Error.hpp"

namespace PA::Object::Menu::Notif {

    Error::Error(std::string message, PA::Vector2<int> pos, PA::Vector2<int> dim)
    : ANotif(message, pos, dim)
    {
        this->text->setColor(SDL_Color{200, 0, 0, 200});
    }

}