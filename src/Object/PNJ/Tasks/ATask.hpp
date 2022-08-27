#ifndef __PA_OBJECT_PNJ_TASKS_TASK_HPP__
    #define __PA_OBJECT_PNJ_TASKS_TASK_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include <string>

class PA::Object::PNJ::Task::ATask {

    public:
    enum Status {
        NOT_STARTED,
        IN_PROGRESS,
        DONE
    };

    private:
    std::string name = "";
    std::string description = "";
    Status status = NOT_STARTED;

    public:
    ATask(std::string name, std::string description);

};

#endif