#ifndef ARRAY_PARSER_HPP
#define ARRAY_PARSER_HPP

#include <string>

#include "parsers/AbstractParser.hpp"
#include "base_elements/JsonElement.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class ArrayParser : AbstractParser
    {
    public:
        ArrayParser(Config *config) : AbstractParser(config) {}
        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif