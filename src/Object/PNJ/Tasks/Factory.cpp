#include "Object/PNJ/Tasks/Factory.hpp"

namespace PA::Object::PNJ::Task {
    
    Factory::Factory()
    {
        this->factory["buildWallBrick"] = CREATE_TASK_LAMBDA(WallTask);
    }

    std::shared_ptr<ATask> Factory::create(std::string component)
    {
        if (this->factory.find(component) != this->factory.end())
            return (this->factory[component]());
        throw PA::Error::InvalidArgument("Task not found '" + component + "'", __FILE__);
    }

}