#include "BadInstance.hpp"

namespace KA::Error {

    BadInstance::BadInstance(const std::string &message, const std::string &where)
    : AError(message, where, "BadInstance") {
        
    }
}