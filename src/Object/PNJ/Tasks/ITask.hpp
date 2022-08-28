#ifndef __PA_OBJECT_TASKS_ITASK_HPP__
    #define __PA_OBJECT_TASKS_ITASK_HPP__

    #include "Object/ObjectNamespace.hpp"

class PA::Object::PNJ::Task::ITask {
    public:
    virtual ~ITask() = default;
    virtual bool isDone() const = 0;
    virtual void update() = 0;
};

#endif