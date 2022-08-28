#ifndef __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__
    #define __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include <iostream>

class PA::Object::PNJ::Task::WallTask : public PA::Object::PNJ::Task::ATask {
    
    public:
    WallTask();
    void update();

};

#endif