#ifndef STRING_PARSER_HPP
#define STRING_PARSER_HPP

#include <string>

#include "base_elements/ArrayElement.hpp"
#include "parsers/AbstractParser.hpp"

class StringParser : AbstractParser
{
public:
    StringParser() = default;
    ArrayElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif