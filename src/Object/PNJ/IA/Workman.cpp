#include "Object/PNJ/IA/Workman.hpp"

namespace PA::Object::PNJ::IA {

    Workman::Workman() {
        this->speed = {1, 1};
        this->moveTimeOffset = 0.01;
        this->maxMoveOffset = 30;
    }

}