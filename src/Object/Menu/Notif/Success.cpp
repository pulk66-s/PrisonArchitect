#include "Object/Menu/Notif/Success.hpp"

namespace PA::Object::Menu::Notif {

    Success::Success(std::string message, PA::Vector2i pos, PA::Vector2i dim)
    : ANotif(message, pos, dim)
    {
        this->text->setColor(SDL_Color{0, 200, 0, 200});
    }


}