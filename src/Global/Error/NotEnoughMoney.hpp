#ifndef __PA_ERROR_NOT_ENOUGH_MONEY_HPP__
    #define __PA_ERROR_NOT_ENOUGH_MONEY_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include "Global/Error/AError.hpp"

class PA::Error::NotEnoughMoney : public PA::Error::AError {

    public:
    NotEnoughMoney(std::string message, std::string file);
};

#endif