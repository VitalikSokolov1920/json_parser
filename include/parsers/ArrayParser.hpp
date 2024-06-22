#ifndef ARRAY_PARSER_HPP
#define ARRAY_PARSER_HPP

#include <string>

#include "parsers/AbstractParser.hpp"
#include "base_elements/JsonElement.hpp"

namespace JSON
{
    class ArrayParser : AbstractParser
    {
    public:
        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif