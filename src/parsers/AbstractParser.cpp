#include "parsers/AbstractParser.hpp"

void JSON::AbstractParser::setError(const std::string &error, std::string::const_iterator curIter, int maxSymbols)
{
    err = error;
    hasErr = true;
}
std::string JSON::AbstractParser::error() const
{
    return err;
}

bool JSON::AbstractParser::hasError() const
{
    return hasErr;
}
