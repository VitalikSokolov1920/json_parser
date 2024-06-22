#ifndef ABSTRACT_PARSER_HPP
#define ABSTRACT_PARSER_HPP

#include <string>

#include "base_elements/JsonElement.hpp"

namespace JSON
{
    enum ParserError
    {
        UNEXPECTED_SYMBOL
    };

    class AbstractParser
    {
    private:
        std::string err;
        bool hasErr;

    public:
        AbstractParser() = default;
        virtual JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr) = 0;

    protected:
        // TODO: переписать, чтобы был код ошибки + подстрока, хранящая место, где ошибка
        void setError(std::string);

    public:
        std::string error() const;
        bool hasError() const;
    };
}

#endif