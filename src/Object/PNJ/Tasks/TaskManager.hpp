#ifndef __PA_OBJECT_TASKS_TASKMANAGER_HPP__
    #define __PA_OBJECT_TASKS_TASKMANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include <vector>

class PA::Object::PNJ::Task::TaskManager {

    private:
    std::vector<ATask> tasks;

    public:
    void addTask(ATask task);

};

#endif