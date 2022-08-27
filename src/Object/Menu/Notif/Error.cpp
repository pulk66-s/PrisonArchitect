#include "Object/Menu/Notif/Error.hpp"

namespace PA::Object::Menu::Notif {

    Error::Error(std::string message, PA::Vector2i pos, PA::Vector2i dim)
    : ANotif(message, pos, dim)
    {
        this->text->setColor(SDL_Color{200, 0, 0, 200});
    }

}