#include "Object/PNJ/Tasks/ATask.hpp"

namespace PA::Object::PNJ::Task {
    ATask::ATask(std::string name, std::string description) {
        this->name = name;
        this->description = description;
    }
}