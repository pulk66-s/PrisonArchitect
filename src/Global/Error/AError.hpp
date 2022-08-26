#ifndef __GLOBAL_ERROR_AERROR_HPP__
    #define __GLOBAL_ERROR_AERROR_HPP__

    #include "Global/GlobalNamespace.hpp"
    #include <exception>
    #include <string>
    #include <iostream>

class PA::Error::AError : public std::exception
{
    private:
        std::string message;
        std::string where_message;
        std::string type_message;

    public:
    AError(const std::string &message, const std::string &where, std::string type="Unknown");
    const char *what() const noexcept;
    const char *where() const noexcept;
    const char *type() const noexcept;
    const char *get() const noexcept;

};

#endif