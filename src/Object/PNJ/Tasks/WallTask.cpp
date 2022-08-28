#include "Object/PNJ/Tasks/WallTask.hpp"

namespace PA::Object::PNJ::Task {
    
    WallTask::WallTask()
    : ATask("WallTask", "Constructing a wall")
    {

    }

    void WallTask::update() {
        std::cout << "update WallTask" << std::endl;
    }

}