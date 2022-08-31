#include "Object/PNJ/Tasks/Tasks.hpp"

namespace PA::Object::PNJ::Task {

    Tasks::Tasks(std::shared_ptr<IA::Ia> ia)
    {
        this->ia = ia;
    }

    void Tasks::addTask(std::shared_ptr<ATask> task) {
        this->tasks.push_back(task);
    }

    int Tasks::size() const {
        return (this->tasks.size());
    }

    void Tasks::update() {
        if (this->size() > 0) {
            this->tasks[0]->update();
            if (this->tasks[0]->isDone())
                this->tasks.erase(this->tasks.begin());
        }
    }

    std::shared_ptr<ATask> Tasks::getCurrTask() {
        if (this->size() > 0)
            return (this->tasks[0]);
        else
            return (nullptr);
    }

}