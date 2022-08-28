#ifndef __PA_OBJECT_TASKS_TASKS_HPP__
    #define __PA_OBJECT_TASKS_TASKS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include <vector>
    #include <memory>
    #include <iostream>

class PA::Object::PNJ::Task::Tasks {

    private:
    std::vector<std::shared_ptr<ATask>> tasks;

    public:
    void addTask(std::shared_ptr<ATask> task);
    int size() const;
    void update();

};

#endif