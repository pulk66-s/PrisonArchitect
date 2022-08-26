#ifndef __GLOBAL_ERROR_BADINSTANCE_HPP__
    #define __GLOBAL_ERROR_BADINSTANCE_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include "AError.hpp"

class KA::Error::BadInstance : public KA::Error::AError {
    public:
    BadInstance(const std::string &message, const std::string &where);
};

#endif