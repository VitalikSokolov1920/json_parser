#include "parsers/AbstractParser.hpp"

void JSON::AbstractParser::setError(std::string error)
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
