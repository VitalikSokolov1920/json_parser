#include "parsers/AbstractParser.hpp"

void AbstractParser::setError(std::string error)
{
    err = error;
    hasErr = true;
}
std::string AbstractParser::error() const
{
    return err;
}

bool AbstractParser::hasError() const
{
    return hasErr;
}
