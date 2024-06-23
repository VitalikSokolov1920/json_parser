#ifndef NULL_PARSER_HPP
#define NULL_PARSER_HPP

#include "parsers/AbstractParser.hpp"
#include "base_elements/JsonElement.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class NullParser : AbstractParser
    {
    public:
        NullParser(Config *config) : AbstractParser(config) {}

        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr);
    };
}

#endif