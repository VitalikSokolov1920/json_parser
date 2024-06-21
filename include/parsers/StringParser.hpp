#ifndef STRING_PARSER_HPP
#define STRING_PARSER_HPP

#include <string>

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"

class StringParser : AbstractParser
{
public:
    StringParser() = default;
    JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif