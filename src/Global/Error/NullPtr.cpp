#include "Global/Error/NullPtr.hpp"

namespace PA::Error {

    NullPtr::NullPtr(std::string message, std::string file)
    : AError(message, file, "NullPtr") {

    }

}