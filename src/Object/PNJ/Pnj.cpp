#include "Pnj.hpp"

namespace PA::Object::PNJ {

    Pnj::Pnj(std::string path, PA::Vector2<int> pos, int variant)
    {
        this->pos = pos;
        this->nb_variant = variant;
        this->spriteSheet = std::make_shared<PA::Lib::SDL2::Graphic::SpriteSheet>(
            path, PA::Vector2<int>{4, 4}, PA::Vector2<int>{0, 0}, this->grid->getSquareDim()
        );
        if (variant > 1) {
            this->currVariant = std::rand() % variant;
            this->spriteSheet->setIndex({0, this->currVariant});
        }
    }

    Pnj::~Pnj()
    {
    }

    void Pnj::draw()
    {
        this->spriteSheet->draw();
    }

    void Pnj::iaUpdate() {
        std::shared_ptr<Task::ATask> task = this->tasks->getCurrTask();
        if (task != nullptr) {
            std::shared_ptr<PA::Vector2<int>> goTo = task->getGoTo();
            this->ia->setGoToPos(goTo);
            if (this->arrivedToGoTo()) {
                this->tasks->getCurrTask()->setArrived(true);
            }
        }
        this->ia->update(&this->pos, this->spriteSheet, this->currVariant);
    }

    void Pnj::update()
    {
        this->tasks->update();
        this->iaUpdate();
    }

    int Pnj::getNbTask() const
    {
        return (this->tasks->size());
    }

    void Pnj::addTask(std::shared_ptr<Task::ATask> task)
    {
        this->tasks->addTask(task);
    }

    std::shared_ptr<Item::AItem> Pnj::getItemCarry()
    {
        return (this->itemCarry);
    }

    void Pnj::setItemCarry(std::shared_ptr<Item::AItem> item)
    {
        if (this->tasks->getCurrTask() != nullptr) {
            this->tasks->getCurrTask()->setItemCarry(item != nullptr);
        }
        this->itemCarry = item;
    }

    void Pnj::setItemCarry(Item::AItem item)
    {
        this->itemCarry = std::make_shared<Item::AItem>(item);
    }

    bool Pnj::arrivedToGoTo() {
        try {
            PA::Vector2<int> goToPos = this->ia->getGoToPos();
            if (this->pos == goToPos) {
                return (true);
            }
        } catch (PA::Error::NullPtr &e) {
            return (false);
        }
        return (false);
    }

    std::shared_ptr<Task::ATask> Pnj::getCurrTask()
    {
        return (this->tasks->getCurrTask());
    }

    PA::Vector2<int> Pnj::getPos() const
    {
        return (this->pos);
    }

}
