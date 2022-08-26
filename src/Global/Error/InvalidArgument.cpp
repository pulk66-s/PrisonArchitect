#include "InvalidArgument.hpp"

namespace KA::Error {

    InvalidArgument::InvalidArgument(const std::string &message, const std::string &where)
    : AError(message, where, "InvalidArgument") {
        
    }
}