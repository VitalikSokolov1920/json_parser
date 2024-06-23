#ifndef OBJECT_PARSER_HPP
#define OBJECT_PARSER_HPP

#include <unordered_map>
#include <string>

#include "base_elements/JsonElement.hpp"
#include "parsers/AbstractParser.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class ObjectParser : AbstractParser
    {
    public:
        ObjectParser(Config *config) : AbstractParser(config) {}

        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif