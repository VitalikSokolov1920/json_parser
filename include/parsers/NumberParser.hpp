#ifndef NUMBER_PARSER_HPP
#define NUMBER_PARSER_HPP

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class NumberParser : AbstractParser
    {
    public:
        NumberParser(Config *config) : AbstractParser(config) {}

        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif