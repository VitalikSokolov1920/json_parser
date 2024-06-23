#ifndef ABSTRACT_PARSER_HPP
#define ABSTRACT_PARSER_HPP

#include <string>

#include "base_elements/JsonElement.hpp"
#include "config/Config.hpp"

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

    protected:
        Config *config;

    public:
        AbstractParser(Config *config) : config(config) {}

    protected:
        virtual JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr) = 0;
        void setError(const std::string &, std::string::const_iterator, int = 20);

    public:
        std::string error() const;
        bool hasError() const;
    };
}

#endif