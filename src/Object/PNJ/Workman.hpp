#ifndef __OBJECT_PNJ_WORKMAN_HPP__
    #define __OBJECT_PNJ_WORKMAN_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Pnj.hpp"
    #include "Lib/SDL2/Renderer.hpp"
    #include "IA/Workman.hpp"

class KA::Object::PNJ::Workman : public KA::Object::PNJ::Pnj {
    public:
    Workman(KA::Vector2i pos={0, 0});
};

#endif