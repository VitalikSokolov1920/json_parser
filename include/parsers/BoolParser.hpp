#ifndef BOOL_PARSER_HPP
#define BOOL_PARSER_HPP

#include <string>

#include "parsers/AbstractParser.hpp"
#include "base_elements/JsonElement.hpp"

class BoolParser : AbstractParser
{
public:
    BoolParser() = default;
    JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif