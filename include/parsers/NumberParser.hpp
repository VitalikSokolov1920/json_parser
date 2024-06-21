#ifndef NUMBER_PARSER_HPP
#define NUMBER_PARSER_HPP

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"

class NumberParser : AbstractParser
{
public:
    NumberParser();
    JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif