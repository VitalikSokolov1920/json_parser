#ifndef OBJECT_PARSER_HPP
#define OBJECT_PARSER_HPP

#include <unordered_map>
#include <string>

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"

namespace JSON
{
    class ObjectParser : AbstractParser
    {
        // std::unordered_map<std::string, JsonElement> fields;

    public:
        ObjectParser() = default;

        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif