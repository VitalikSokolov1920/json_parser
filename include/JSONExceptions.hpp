#ifndef JSONEXCEPTIONS_HPP
#define JSONEXCEPTIONS_HPP

#include <exception>
#include <string>

#include "base_elements/JsonElement.hpp"

namespace JSON
{
    namespace JSONException
    {
        class InvalidOpenFileException : std::exception
        {
            std::string path;

        public:
            InvalidOpenFileException(const std::string &);
            InvalidOpenFileException(const char *);
            const char *what() const noexcept;
        };

        class EOFileException : std::exception
        {
        };

        class UnsupportedConvertion : std::exception
        {
            std::string error;

        public:
            UnsupportedConvertion(const JsonElement &elem, std::string type);
            UnsupportedConvertion(const JsonElement &elem, const char *type);
            const char *what() const noexcept;
        };
    } // namespace JSONException

} // namespace JSON

#endif