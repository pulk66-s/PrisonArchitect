#ifndef __PA_GLOBAL_ERROR_NULLPTR_HPP__
    #define __PA_GLOBAL_ERROR_NULLPTR_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include "Global/Error/AError.hpp"

class PA::Error::NullPtr : public PA::Error::AError {

    public:
    NullPtr(std::string message, std::string file);

};

#endif