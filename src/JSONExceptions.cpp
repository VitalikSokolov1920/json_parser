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

JSON::JSONException::UnsupportedIndexOperation::UnsupportedIndexOperation(const JsonElement &elem, std::string property)
{
    error = "Can't get property \"" + property + "\" from elem " + elem.toString();
}

JSON::JSONException::UnsupportedIndexOperation::UnsupportedIndexOperation(const JsonElement &elem, int index)
{
    error = "Can't get index \"" + std::to_string(index) + "\" from elem " + elem.toString();
}

JSON::JSONException::IndexOutOfRange::IndexOutOfRange(const JsonElement &elem, int index)
{
    error = "Index " +
            std::to_string(index) +
            " out of range of elem: " +
            elem.toString() + "(len = " +
            std::to_string(elem.Elem().arrayElem->size()) + ")";
}

JSON::JSONException::PropertyNotExist::PropertyNotExist(const JsonElement &elem, std::string property)
{
    error = "Property \"" + property + "\" does not exist in object " + elem.toString();
}
