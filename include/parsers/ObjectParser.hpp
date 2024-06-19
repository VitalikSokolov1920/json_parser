#ifndef OBJECT_PARSER_HPP
#define OBJECT_PARSER_HPP

#include <unordered_map>
#include <string>

#include "base_elements/ArrayElement.hpp"
#include "parsers/AbstractParser.hpp"

class ObjectParser : AbstractParser
{
    // std::unordered_map<std::string, ArrayElement> fields;

public:
    ObjectParser() = default;

    ArrayElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
};

#endif