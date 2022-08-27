#ifndef __PA_GLOBAL_ERROR_NOTIFSUCCESS_HPP__
    #define __PA_GLOBAL_ERROR_NOTIFSUCCESS_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include "Global/Error/AError.hpp"

class PA::Error::NotifSuccess : public PA::Error::AError {

    public:
    NotifSuccess(std::string message, std::string file);

};

#endif