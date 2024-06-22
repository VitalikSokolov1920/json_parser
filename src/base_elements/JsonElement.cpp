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

JsonElement::JsonElement(const bool &v)
{
    type = BOOL;
    elem.boolElem = new bool{v};
}

JsonElement::JsonElement(const int &v)
{
    type = INT;
    elem.intElem = new int{v};
}

JsonElement::JsonElement(const double &v)
{
    type = DOUBLE;
    elem.doubleElem = new double{v};
}

JsonElement::JsonElement(const std::string &v)
{
    type = STRING;
    elem.strElem = new std::string{v};
}

JsonElement::JsonElement(const std::vector<JsonElement> &v)
{
    type = ARRAY;
    elem.arrayElem = new std::vector<JsonElement>(v);
}

JsonElement::JsonElement(const std::unordered_map<std::string, JsonElement> &object)
{
    type = OBJECT;
    elem.objectElem = new std::unordered_map<std::string, JsonElement>(object);
}

JsonElement::JsonElement(void *null)
{
    type = JSON_NULL;
    elem.null = nullptr;
}

JsonElement::JsonElement(const JsonElement &other)
{
    type = NOT_SET;

    *this = other;
}

JsonElement &JsonElement::operator=(const JsonElement &other)
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

std::ostream &operator<<(std::ostream &out, const JsonElement &elem)
{
    switch (elem.type)
    {
    case JsonElement::BOOL:
        out << "Boolean: " << *elem.elem.boolElem;
        break;
    case JsonElement::INT:
        out << "Interger: " << *elem.elem.intElem;
        break;
    case JsonElement::DOUBLE:
        out << "Double: " << *elem.elem.doubleElem;
        break;
    case JsonElement::STRING:
        out << "String: " << *elem.elem.strElem;
        break;
    case JsonElement::ARRAY:
    {
        auto iter = elem.elem.arrayElem->begin();

        out << "Array:\n";
        for (; iter != elem.elem.arrayElem->end(); iter++)
        {
            out << *iter << std::endl;
        }
        break;
    }

    case JsonElement::OBJECT:
    {
        for (auto iter = elem.elem.objectElem->begin(); iter != elem.elem.objectElem->end(); iter++)
        {
            std::cout << "Property: " << iter->first << std::endl;
            std::cout << "Value: " << iter->second << std::endl;
        }

        break;
    }
    }

    return out;
}

JsonElement::~JsonElement()
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