#include <iostream>

#include "base_elements/JsonElement.hpp"

/*
switch (type)
        {
        case BOOL:
            break;
        case INT:
            break;
        case DOUBLE:
            break;
        case STRING:
            break;
        case ARRAY:
            break;
        case OBJECT:
            break;
        case JSON_NULL:
            break;
        }
*/

JSON::JsonElement::JsonElement(const bool &v)
{
    type = BOOL;
    elem.boolElem = new bool{v};
}

JSON::JsonElement::JsonElement(const int &v)
{
    type = INT;
    elem.intElem = new int{v};
}

JSON::JsonElement::JsonElement(const double &v)
{
    type = DOUBLE;
    elem.doubleElem = new double{v};
}

JSON::JsonElement::JsonElement(const std::string &v)
{
    type = STRING;
    elem.strElem = new std::string{v};
}

JSON::JsonElement::JsonElement(const std::vector<JsonElement> &v)
{
    type = ARRAY;
    elem.arrayElem = new std::vector<JsonElement>(v);
}

JSON::JsonElement::JsonElement(const std::unordered_map<std::string, JsonElement> &object)
{
    type = OBJECT;
    elem.objectElem = new std::unordered_map<std::string, JsonElement>(object);
}

JSON::JsonElement::JsonElement(void *null)
{
    type = JSON_NULL;
    elem.null = nullptr;
}

JSON::JsonElement::JsonElement(const JsonElement &other)
{
    type = NOT_SET;

    *this = other;
}

JSON::JsonElement &JSON::JsonElement::operator=(const JsonElement &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (type != NOT_SET)
    {
        switch (type)
        {
        case BOOL:
            delete elem.boolElem;
            break;
        case INT:
            delete elem.intElem;
            break;
        case DOUBLE:
            delete elem.doubleElem;
            break;
        case STRING:
            delete elem.strElem;
            break;
        case ARRAY:
            delete elem.arrayElem;
            break;
        case OBJECT:
            delete elem.objectElem;
            break;
        }
    }

    type = other.type;

    switch (type)
    {
    case BOOL:
        elem.boolElem = new bool{*other.elem.boolElem};
        break;
    case INT:
        elem.intElem = new int{*other.elem.intElem};
        break;
    case DOUBLE:
        elem.doubleElem = new double{*other.elem.doubleElem};
        break;
    case STRING:
        elem.strElem = new std::string{*other.elem.strElem};
        break;
    case ARRAY:
        elem.arrayElem = new std::vector<JsonElement>(*other.elem.arrayElem);
        break;
    case OBJECT:
        elem.objectElem = new std::unordered_map<std::string, JsonElement>(*other.elem.objectElem);
        break;
    }

    return *this;
}

namespace JSON
{
    std::ostream &operator<<(std::ostream &out, const JSON::JsonElement &elem)
    {
        switch (elem.type)
        {
        case JSON::JsonElement::BOOL:
            out << "Boolean: " << *elem.elem.boolElem;
            break;
        case JSON::JsonElement::INT:
            out << "Interger: " << *elem.elem.intElem;
            break;
        case JSON::JsonElement::DOUBLE:
            out << "Double: " << *elem.elem.doubleElem;
            break;
        case JSON::JsonElement::STRING:
            out << "String: " << *elem.elem.strElem;
            break;
        case JSON::JsonElement::ARRAY:
        {
            auto iter = elem.elem.arrayElem->begin();

            out << "Array:\n";
            for (; iter != elem.elem.arrayElem->end(); iter++)
            {
                out << *iter << std::endl;
            }
            break;
        }

        case JSON::JsonElement::OBJECT:
        {
            for (auto iter = elem.elem.objectElem->begin(); iter != elem.elem.objectElem->end(); iter++)
            {
                std::cout << "Property: " << iter->first << std::endl;
                std::cout << "Value: " << iter->second << std::endl;
            }

            break;
        }
        case JSON::JsonElement::JSON_NULL:
        {
            out << "Null";
        }
        }

        return out;
    }

}

JSON::JsonElement::~JsonElement()
{
    if (type != NOT_SET)
    {
        switch (type)
        {
        case BOOL:
            delete elem.boolElem;
            break;
        case INT:
            delete elem.intElem;
            break;
        case DOUBLE:
            delete elem.doubleElem;
            break;
        case STRING:
            delete elem.strElem;
            break;
        case ARRAY:
            delete elem.arrayElem;
            break;
        case OBJECT:
            delete elem.objectElem;
            break;
        }
    }
}