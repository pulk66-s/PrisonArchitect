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
        std::shared_ptr<Task::ATask> task = this->tasks.getCurrTask();
        if (task != nullptr) {
            std::shared_ptr<PA::Vector2<int>> goTo = task->getGoTo();
            if (goTo != nullptr) {
                this->ia->setGoToPos(*goTo);
            }
        }
        this->ia->update(&this->pos, this->spriteSheet, this->currVariant);
    }

    void Pnj::update()
    {
        this->tasks.update();
        this->iaUpdate();
    }

    int Pnj::getNbTask() const
    {
        return (this->tasks.size());
    }

    void Pnj::addTask(std::shared_ptr<Task::ATask> task)
    {
        this->tasks.addTask(task);
    }

}
