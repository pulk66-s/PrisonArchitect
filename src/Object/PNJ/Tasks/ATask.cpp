#include "Object/PNJ/Tasks/ATask.hpp"

namespace PA::Object::PNJ::Task {
    ATask::ATask(std::string name, std::string description) {
        this->name = name;
        this->description = description;
    }

    ATask::~ATask() {
    }

    bool ATask::isDone() const {
        return (this->status == DONE);
    }

    void ATask::addGoTo(PA::Vector2<int> goTo) {
        this->goTo.push(std::make_shared<PA::Vector2<int>>(goTo));
    }

    std::shared_ptr<PA::Vector2<int>> ATask::getGoTo() const {
        if (this->goTo.size() == 0) {
            return (nullptr);
        }
        return (this->goTo.front());
    }

    void ATask::setArrived(bool arrived) {
        this->arrived = arrived;
    }

    bool ATask::getArrived() const {
        return (this->arrived);
    }

    ATask::Action ATask::getAction() const {
        return (this->action);
    }

    void ATask::setItemCarry(bool item) {
        this->itemCarry = item;
    }

    void ATask::setAction(Action action) {
        this->action = action;
    }

    void ATask::popGoTo() {
        if (this->goTo.size() > 0) {
            this->goTo.pop();
        }
    }

}