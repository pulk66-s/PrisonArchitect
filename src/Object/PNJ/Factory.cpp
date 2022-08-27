#include "Object/PNJ/Factory.hpp"

namespace PA::Object::PNJ {
    
    Factory::Factory() {
        this->factory["Workman"] = CREATE_PNJ_LAMBDA(Workman);
    }

    std::shared_ptr<Pnj> Factory::create(std::string component, Vector2i pos) {
        return (this->factory[component](pos));
    }

}