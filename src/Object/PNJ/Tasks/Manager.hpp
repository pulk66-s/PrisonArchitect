#ifndef __PA_OBJECT_PNJ_TASKS_MANAGER_HPP__
    #define __PA_OBJECT_PNJ_TASKS_MANAGER_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/Factory.hpp"
    #include "Object/PNJ/Pnjs.hpp"
    #include "Object/PNJ/IPnj.hpp"
    #include <iostream>

class PA::Object::PNJ::Task::Manager {

    private:
    Factory factory;
    std::shared_ptr<PNJ::Pnjs> pnjs = PNJ::Pnjs::getInstance();

    public:
    void createTask(std::string taskName);

};

#endif