#ifndef __PA_OBJECT_PNJ_IPNJ_HPP__
    #define __PA_OBJECT_PNJ_IPNJ_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include <memory>

class PA::Object::PNJ::IPnj {

    public:
    virtual ~IPnj() {};
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual int getNbTask() const = 0;
    virtual void addTask(std::shared_ptr<Task::ATask> task) = 0;

};

#endif