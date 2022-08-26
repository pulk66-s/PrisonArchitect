#include "AError.hpp"

namespace KA::Error {
    AError::AError(const std::string &message, const std::string &where, std::string type)
    : message(message), where_message(where), type_message(type) {
        
    }

    const char *AError::what() const throw() {
        return (this->message.c_str());
    }

    const char *AError::where() const throw() {
        return (this->where_message.c_str());
    }

    const char *AError::type() const throw() {
        return (this->type_message.c_str());
    }

    const char *AError::get() const throw() {
        std::string message = "Error " + this->type_message + ": " + this->message + " in " + this->where_message;
        return (message.c_str());
    }

}