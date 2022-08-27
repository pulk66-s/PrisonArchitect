#ifndef __PA_OBJECT_MENU_ERRORS_HPP__
    #define __PA_OBJECT_MENU_ERRORS_HPP__

    #include "Object/ObjectNamespace.hpp"
    #include "Object/Menu/Notif/Error.hpp"
    #include "Global/Vector.hpp"
    #include <vector>
    #include <algorithm>
    #include <numeric>

class PA::Object::Menu::Notif::Errors {

    private:
    std::vector<Error> errors = {};
    PA::Vector2i pos = {400, 100};
    PA::Vector2i textDim = {300, 30};
    PA::Vector2i buff = {0, 5};

    public:
    void draw();
    void update();
    void addError(std::string message);

};

#endif