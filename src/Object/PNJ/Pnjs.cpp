#include "Object/PNJ/Pnjs.hpp"

namespace PA::Object::PNJ {

    std::shared_ptr<Pnjs> Pnjs::getInstance() {
        static std::shared_ptr<Pnjs> instance = std::make_shared<Pnjs>();
        return (instance);
    }

    Pnjs::Pnjs() {
        this->pnjs = std::make_shared<std::vector<std::shared_ptr<Pnj>>>();
    }

    void Pnjs::add(std::shared_ptr<Pnj> pnj) {
        pnjs->push_back(pnj);
    }

    std::shared_ptr<std::vector<std::shared_ptr<Pnj>>> Pnjs::getPnjs() {
        return (this->pnjs);
    }

    std::shared_ptr<Pnj> Pnjs::getLaziest() {
        if (pnjs->size() == 0)
            return (nullptr);
        std::shared_ptr<Pnj> laziest = pnjs->at(0);
        for (auto pnj : *pnjs) {
            if (pnj->getNbTask() < laziest->getNbTask())
                laziest = pnj;
        }
        return (laziest);
    }

}