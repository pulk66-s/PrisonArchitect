#include "Global/Error/NotEnoughMoney.hpp"

namespace PA::Error {
        
    NotEnoughMoney::NotEnoughMoney(std::string message, std::string file)
    : AError(message, file, "Not enough money Error") {

    }

}