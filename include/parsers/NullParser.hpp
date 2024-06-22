#ifndef NULL_PARSER_HPP
#define NULL_PARSER_HPP

#include "parsers/AbstractParser.hpp"
#include "base_elements/JsonElement.hpp"

class NullParser : AbstractParser
{
public:
    JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif