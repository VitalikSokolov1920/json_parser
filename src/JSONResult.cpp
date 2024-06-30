#include <cstdlib>
#include <iostream>
#include <sstream>

#include "JSONResult.hpp"
#include "JSONExceptions.hpp"

JSON::JSONDocument JSON::JSONDocument::operator[](std::string property)
{
    if (elem.Type() != JsonElement::OBJECT)
    {
        throw JSONException::UnsupportedIndexOperation(elem, property);
    }

    if (elem.Elem().objectElem->find(property) == elem.Elem().objectElem->end())
    {
        throw JSONException::PropertyNotExist(elem, property);
    }

    return JSONDocument((*elem.Elem().objectElem)[property]);
}

JSON::JSONDocument JSON::JSONDocument::operator[](int index)
{
    switch (elem.Type())
    {
    case JsonElement::BOOL:
    case JsonElement::INT:
    case JsonElement::DOUBLE:
    case JsonElement::JSON_NULL:
    case JsonElement::OBJECT:
        throw JSONException::UnsupportedIndexOperation(elem, index);
        break;
    case JsonElement::STRING:
        if (index >= elem.Elem().strElem->length())
        {
            throw JSONException::IndexOutOfRange(elem, index);
        }

        return JSONDocument((*elem.Elem().strElem)[index]);
    case JsonElement::ARRAY:

        if (index >= elem.Elem().arrayElem->size())
        {
            throw JSONException::IndexOutOfRange(elem, index);
        }

        return JSONDocument((*elem.Elem().arrayElem)[index]);
    }

    return JSONDocument(elem);
}

std::string JSON::JSONDocument::toString()
{
    return elem.toString();
}

std::optional<int> JSON::JSONDocument::toInt()
{
    switch (elem.Type())
    {
    case JsonElement::BOOL:
        return *elem.Elem().boolElem ? 1 : 0;
    case JsonElement::INT:
        return *elem.Elem().intElem;
    case JsonElement::DOUBLE:
        return *elem.Elem().doubleElem;
    case JsonElement::STRING:
    {
        std::istringstream stream(*elem.Elem().strElem);

        int value;

        stream >> value;

        if (!stream.fail())
        {
            return value;
        }
    }
    }

    return std::nullopt;
}

std::optional<double> JSON::JSONDocument::toDouble()
{
    switch (elem.Type())
    {
    case JsonElement::BOOL:
        return *elem.Elem().boolElem ? 1 : 0;
        break;
    case JsonElement::INT:
        return *elem.Elem().intElem;
        break;
    case JsonElement::DOUBLE:
        return *elem.Elem().doubleElem;
        break;
    case JsonElement::STRING:
    {
        double value;

        std::istringstream stream(*elem.Elem().strElem);

        stream >> value;

        if (!stream.fail())
        {
            return value;
        }
        break;
    }
    }

    return std::nullopt;
}

std::optional<bool> JSON::JSONDocument::toBool()
{
    switch (elem.Type())
    {
    case JsonElement::BOOL:
        return *elem.Elem().boolElem;
    case JsonElement::INT:
        return (*elem.Elem().intElem > 0);
    case JsonElement::DOUBLE:
        return (*elem.Elem().doubleElem > 0);
    case JsonElement::STRING:
        return elem.Elem().strElem->length() != 0;
    case JsonElement::JSON_NULL:
        return false;
    }

    return std::nullopt;
}
