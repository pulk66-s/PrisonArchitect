#ifndef __PA_OBJECT_PNJ_TASKS_TASK_HPP__
    #define __PA_OBJECT_PNJ_TASKS_TASK_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Tasks/ITask.hpp"
    #include "Global/Vector.hpp"
    #include <string>
    #include <memory>

class PA::Object::PNJ::Task::ATask : public PA::Object::PNJ::Task::ITask {

    public:
    enum Status {
        NOT_STARTED,
        IN_PROGRESS,
        DONE
    };
    enum Action {
        GET_ITEM,
        NONE
    };

    protected:
    std::string name = "";
    std::string description = "";
    Status status = NOT_STARTED;
    std::shared_ptr<PA::Vector2<int>> goTo = nullptr;
    bool arrived = false;
    bool itemCarry = false;
    Action action = NONE;

    public:
    ATask(std::string name, std::string description);
    ~ATask();
    bool isDone() const;
    virtual void update() = 0;
    void setGoTo(PA::Vector2<int> goTo);
    std::shared_ptr<PA::Vector2<int>> getGoTo() const;
    void setArrived(bool arrived);
    bool getArrived() const;
    Action getAction() const;
    void setAction(Action action);
    void setItemCarry(bool item);

};

#endif