#ifndef __PA_OBJECT_PNJ_FACTORY_HPP__
    #define __PA_OBJECT_PNJ_FACTORY_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/IPnj.hpp"
    #include "Object/PNJ/Workman.hpp"
    #include "Global/Vector.hpp"
    #include <unordered_map>
    #include <string>

    #define CREATE_PNJ_LAMBDA(className) [](PA::Vector2<int> pos) -> \
    std::shared_ptr<IPnj> { \
        return (std::make_shared<className>(pos)); \
    }

    #define LAMBDA std::function<std::shared_ptr<IPnj>(PA::Vector2<int> pos)>

class PA::Object::PNJ::Factory {

    private:
    std::unordered_map<std::string, LAMBDA> factory;

    public:
    Factory();
    std::shared_ptr<IPnj> create(std::string component, PA::Vector2<int> pos);

};

#endif