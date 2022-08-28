#include "Object/PNJ/Pnjs.hpp"

namespace PA::Object::PNJ {

    std::shared_ptr<Pnjs> Pnjs::getInstance() {
        static std::shared_ptr<Pnjs> instance = std::make_shared<Pnjs>();
        return (instance);
    }

    Pnjs::Pnjs() {
        this->pnjs = std::make_shared<std::vector<std::shared_ptr<IPnj>>>();
    }

    void Pnjs::add(std::shared_ptr<IPnj> pnj) {
        pnjs->push_back(pnj);
    }

    std::shared_ptr<std::vector<std::shared_ptr<IPnj>>> Pnjs::getPnjs() {
        return (this->pnjs);
    }

    std::shared_ptr<IPnj> Pnjs::getLaziest() {
        if (pnjs->size() == 0)
            return (nullptr);
        std::shared_ptr<IPnj> laziest = pnjs->at(0);
        for (auto pnj : *pnjs) {
            if (pnj->getNbTask() < laziest->getNbTask())
                laziest = pnj;
        }
        return (laziest);
    }

}