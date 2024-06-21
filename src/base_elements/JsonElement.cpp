#include <iostream>

#include "base_elements/JsonElement.hpp"

JsonElement::JsonElement(const bool &v)
{
    this->type = BOOL;
    this->elem.boolElem = new bool{v};
}

JsonElement::JsonElement(const int &v)
{
    this->type = INT;
    this->elem.intElem = new int{v};
}

JsonElement::JsonElement(const double &v)
{
    this->type = DOUBLE;
    this->elem.doubleElem = new double{v};
}

JsonElement::JsonElement(const std::string &v)
{
    this->type = STRING;
    this->elem.strElem = new std::string{v};
}

JsonElement::JsonElement(const std::vector<JsonElement> &v)
{
    this->type = ARRAY;
    this->elem.arrayElem = new std::vector<JsonElement>(v);
}

JsonElement::JsonElement(const std::unordered_map<std::string, JsonElement> &object)
{
    this->type = OBJECT;
    this->elem.objectElem = new std::unordered_map<std::string, JsonElement>(object);
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