#include <cstring>

#include "JSONExceptions.hpp"

JSON::JSONException::InvalidOpenFileException::InvalidOpenFileException(const std::string &path) : path(path) {}

JSON::JSONException::InvalidOpenFileException::InvalidOpenFileException(const char *path) : path(path) {}

const char *JSON::JSONException::InvalidOpenFileException::what() const noexcept
{
    std::string out{"Can't open file "};
    out += path;
    return out.c_str();
}

JSON::JSONException::UnsupportedConvertion::UnsupportedConvertion(const JsonElement &elem, std::string type)
{
    error = "Can't convert " + elem.toString() + " to type " + type;
}

JSON::JSONException::UnsupportedConvertion::UnsupportedConvertion(const JsonElement &elem, const char *type)
{
    error = "Can't convert " + elem.toString() + " to type " + type;
}

const char *JSON::JSONException::UnsupportedConvertion::what() const noexcept
{
    return error.c_str();
}
