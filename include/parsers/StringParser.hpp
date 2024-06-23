#ifndef STRING_PARSER_HPP
#define STRING_PARSER_HPP

#include <string>

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class StringParser : AbstractParser
    {
    public:
        StringParser(Config *config) : AbstractParser(config) {}

        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif