#include "Object/PNJ/Factory.hpp"

namespace PA::Object::PNJ {
    
    Factory::Factory() {
        this->factory["Workman"] = CREATE_PNJ_LAMBDA(PNJ::Workman);
    }

    std::shared_ptr<IPnj> Factory::create(std::string component, Vector2<int> pos) {
        return (this->factory[component](pos));
    }

}