#ifndef __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__
    #define __PA_OBJECT_PNH_TASKS_WALLTASK_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ATask.hpp"
    #include "Object/Items/Items.hpp"
    #include <iostream>

class PA::Object::PNJ::Task::WallTask : public PA::Object::PNJ::Task::ATask {
    
    private:
    std::shared_ptr<Item::Items> items = Item::Items::getInstance();
    std::shared_ptr<Item::AItem> item = nullptr;

    void findItem();
    void updateTask();

    public:
    WallTask();
    void update();

};

#endif