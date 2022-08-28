#ifndef __OBJECT_PNJ_WORKMAN_HPP__
    #define __OBJECT_PNJ_WORKMAN_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/PNJ/Pnj.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "IA/Workman.hpp"

class PA::Object::PNJ::Workman : public PA::Object::PNJ::Pnj {
    public:
    Workman(PA::Vector2<int> pos={0, 0});
    ~Workman();
};

#endif