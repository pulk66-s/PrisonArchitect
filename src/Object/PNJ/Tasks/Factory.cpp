#include "Object/PNJ/Tasks/Factory.hpp"

namespace PA::Object::PNJ::Task {
    
    Factory::Factory()
    {
        this->factory["WallTask"] = CREATE_TASK_LAMBDA(WallTask);
    }

    std::shared_ptr<ATask> Factory::create(std::string component)
    {
        return this->factory[component]();
    }

}