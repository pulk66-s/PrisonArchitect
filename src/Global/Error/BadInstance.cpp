#include "BadInstance.hpp"

namespace PA::Error {

    BadInstance::BadInstance(const std::string &message, const std::string &where)
    : AError(message, where, "BadInstance") {
        
    }
}