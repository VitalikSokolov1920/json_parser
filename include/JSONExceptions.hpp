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

        class BaseException : public std::exception
        {
        protected:
            std::string error;

        public:
            const char *what() const noexcept
            {
                return error.c_str();
            }
        };

        class UnsupportedConvertion : public BaseException
        {
        public:
            UnsupportedConvertion(const JsonElement &elem, std::string type);
            UnsupportedConvertion(const JsonElement &elem, const char *type);
        };

        class UnsupportedIndexOperation : public BaseException
        {
        public:
            UnsupportedIndexOperation(const JsonElement &elem, std::string);
            UnsupportedIndexOperation(const JsonElement &elem, int);
        };

        class IndexOutOfRange : public BaseException
        {
        public:
            IndexOutOfRange(const JsonElement &elem, int);
        };

        class PropertyNotExist : public BaseException
        {
        public:
            PropertyNotExist(const JsonElement &elem, std::string);
        };
    } // namespace JSONException

} // namespace JSON

#endif