#ifndef __PA_OBJECT_PNJ_PNJS_HPP__
    #define __PA_OBJECT_PNJ_PNJS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include <vector>
    #include <memory>
    #include "Object/PNJ/IPnj.hpp"

class PA::Object::PNJ::Pnjs {

    private:
    std::shared_ptr<std::vector<std::shared_ptr<IPnj>>> pnjs;

    public:
    Pnjs();
    void add(std::shared_ptr<IPnj> pnj);
    std::shared_ptr<std::vector<std::shared_ptr<IPnj>>> getPnjs();
    static std::shared_ptr<Pnjs> getInstance();
    std::shared_ptr<IPnj> getLaziest();

};

#endif