#include "Global/Error/NotifSuccess.hpp"

namespace PA::Error {

    NotifSuccess::NotifSuccess(std::string message, std::string file) 
    : AError(message, file, "Notif") {

    }

}