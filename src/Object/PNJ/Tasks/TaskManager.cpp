#include "Object/PNJ/Tasks/TaskManager.hpp"

namespace PA::Object::PNJ::Task {

    void TaskManager::addTask(ATask task) {
        this->tasks.push_back(task);
    }

}