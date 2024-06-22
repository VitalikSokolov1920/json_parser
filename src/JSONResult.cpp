#include <cstdlib>
#include <iostream>

#include "JSONResult.hpp"
#include "JSONExceptions.hpp"

JSON::JsonElement JSON::JSONDocument::operator[](std::string property)
{
    if (elem.Type() != JsonElement::OBJECT)
    {
        throw JSONException::UnsupportedIndexOperation(elem, property);
    }

    if (elem.Elem().objectElem->find(property) == elem.Elem().objectElem->end())
    {
        throw JSONException::PropertyNotExist(elem, property);
    }

    return (*elem.Elem().objectElem)[property];
}

JSON::JsonElement JSON::JSONDocument::operator[](int index)
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

        return (*elem.Elem().strElem)[index];
    case JsonElement::ARRAY:

        if (index >= elem.Elem().arrayElem->size())
        {
            throw JSONException::IndexOutOfRange(elem, index);
        }

        return (*elem.Elem().arrayElem)[index];
    }

    return elem;
}

std::string JSON::JSONDocument::toString()
{
    return elem.toString();
}

int JSON::JSONDocument::toInt()
{
    int value;

    switch (elem.Type())
    {
    case JsonElement::BOOL:
        value = *elem.Elem().boolElem ? 1 : 0;
        break;
    case JsonElement::INT:
        value = *elem.Elem().intElem;
        break;
    case JsonElement::DOUBLE:
        value = *elem.Elem().doubleElem;
        break;
    case JsonElement::STRING:
        value = ::atoi(elem.Elem().strElem->c_str());
        break;
    case JsonElement::ARRAY:
        throw JSONException::UnsupportedConvertion(elem, "Array");
        break;
    case JsonElement::OBJECT:
        throw JSONException::UnsupportedConvertion(elem, "Object");
        break;
    case JsonElement::JSON_NULL:
        value = 0;
        break;
    }

    return value;
}

double JSON::JSONDocument::toDouble()
{
    double value;

    switch (elem.Type())
    {
    case JsonElement::BOOL:
        value = *elem.Elem().boolElem ? 1 : 0;
        break;
    case JsonElement::INT:
        value = *elem.Elem().intElem;
        break;
    case JsonElement::DOUBLE:
        value = *elem.Elem().doubleElem;
        break;
    case JsonElement::STRING:
        value = ::atof(elem.Elem().strElem->c_str());
        break;
    case JsonElement::ARRAY:
        throw JSONException::UnsupportedConvertion(elem, "Array");
        break;
    case JsonElement::OBJECT:
        throw JSONException::UnsupportedConvertion(elem, "Object");
        break;
    case JsonElement::JSON_NULL:
        value = 0.0;
        break;
    }

    return value;
}

bool JSON::JSONDocument::toBool()
{
    bool result;

    switch (elem.Type())
    {
    case JsonElement::BOOL:
        result = *elem.Elem().boolElem;
        break;
    case JsonElement::INT:
        result = (*elem.Elem().intElem > 0);
        break;
    case JsonElement::DOUBLE:
        result = (*elem.Elem().doubleElem > 0);
        break;
    case JsonElement::STRING:
        result = elem.Elem().strElem->length() != 0;
        break;
    case JsonElement::ARRAY:
        throw JSONException::UnsupportedConvertion(elem, "Bool");
        break;
    case JsonElement::OBJECT:
        throw JSONException::UnsupportedConvertion(elem, "Bool");
        break;
    case JsonElement::JSON_NULL:
        result = false;
        break;
    }

    return result;
}
