#ifndef __GLOBAL_ERROR_INVALIDARGUMENT_HPP__
    #define __GLOBAL_ERROR_INVALIDARGUMENT_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include "AError.hpp"

class PA::Error::InvalidArgument : public PA::Error::AError
{
    public:
    InvalidArgument(const std::string &message, const std::string &where);
};

#endif