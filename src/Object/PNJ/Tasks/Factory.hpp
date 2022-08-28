#ifndef __PA_OBJECT_PNJ_TASKS_FACTORY_HPP__
    #define __PA_OBJECT_PNJ_TASKS_FACTORY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include "Object/PNJ/Tasks/WallTask.hpp"
    #include "Global/Error/InvalidArgument.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>
    #include <functional>

    #define CREATE_TASK_LAMBDA(className) []() -> std::shared_ptr<ATask> { \
        return (std::make_shared<className>()); \
    }

    #define TASK_LAMBDA std::function<std::shared_ptr<ATask>()>

class PA::Object::PNJ::Task::Factory {

    private:
    std::unordered_map<std::string, TASK_LAMBDA> factory;

    public:
    Factory();
    std::shared_ptr<ATask> create(std::string component);

};

#endif