#ifndef __PA_OBJECT_PNJ_PNJS_HPP__
    #define __PA_OBJECT_PNJ_PNJS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include <vector>
    #include <memory>
    #include "Object/PNJ/Pnj.hpp"

class PA::Object::PNJ::Pnjs {

    private:
    std::shared_ptr<std::vector<std::shared_ptr<Pnj>>> pnjs;

    public:
    Pnjs();
    void add(std::shared_ptr<Pnj> pnj);
    std::shared_ptr<std::vector<std::shared_ptr<Pnj>>> getPnjs();
    static std::shared_ptr<Pnjs> getInstance();
    std::shared_ptr<Pnj> getLaziest();

};

#endif