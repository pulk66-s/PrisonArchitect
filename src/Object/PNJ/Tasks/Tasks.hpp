#ifndef __PA_OBJECT_TASKS_TASKS_HPP__
    #define __PA_OBJECT_TASKS_TASKS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include "Object/PNJ/IA/Ia.hpp"
    #include <vector>
    #include <memory>
    #include <iostream>

class PA::Object::PNJ::Task::Tasks {

    private:
    std::vector<std::shared_ptr<ATask>> tasks;
    std::shared_ptr<IA::Ia> ia = nullptr;

    public:
    Tasks(std::shared_ptr<IA::Ia> ia);
    void addTask(std::shared_ptr<ATask> task);
    int size() const;
    void update();
    std::shared_ptr<ATask> getCurrTask();

};

#endif