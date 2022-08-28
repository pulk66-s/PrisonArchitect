#include "Object/PNJ/Tasks/Manager.hpp"

namespace PA::Object::PNJ::Task {

    void Manager::createTask(std::string taskName) {
        std::shared_ptr<IPnj> pnj = this->pnjs->getLaziest();
        std::shared_ptr<ATask> task = this->factory.create(taskName);
        pnj->addTask(task);
    }

}