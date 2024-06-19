#include <iostream>

#include "base_elements/ArrayElement.hpp"

ArrayElement::ArrayElement(const bool &v)
{
    this->type = BOOL;
    this->elem.boolElem = new bool{v};
}

ArrayElement::ArrayElement(const int &v)
{
    this->type = INT;
    this->elem.intElem = new int{v};
}

ArrayElement::ArrayElement(const double &v)
{
    this->type = DOUBLE;
    this->elem.doubleElem = new double{v};
}

ArrayElement::ArrayElement(const std::string &v)
{
    this->type = STRING;
    this->elem.strElem = new std::string{v};
}

ArrayElement::ArrayElement(const std::vector<ArrayElement> &v)
{
    this->type = ARRAY;
    this->elem.arrayElem = new std::vector<ArrayElement>(v);
}

ArrayElement::ArrayElement(const std::unordered_map<std::string, ArrayElement> &object)
{
    this->type = OBJECT;
    this->elem.objectElem = new std::unordered_map<std::string, ArrayElement>(object);
}
std::ostream &operator<<(std::ostream &out, const ArrayElement &elem)
{
    switch (elem.type)
    {
    case ArrayElement::BOOL:
        out << "Boolean: " << *elem.elem.boolElem;
        break;
    case ArrayElement::INT:
        out << "Interger: " << *elem.elem.intElem;
        break;
    case ArrayElement::DOUBLE:
        out << "Double: " << *elem.elem.doubleElem;
        break;
    case ArrayElement::STRING:
        out << "String: " << *elem.elem.strElem;
        break;
    case ArrayElement::ARRAY:
    {
        auto iter = elem.elem.arrayElem->begin();

        out << "Array:\n";
        for (; iter != elem.elem.arrayElem->end(); iter++)
        {
            out << *iter << std::endl;
        }
        break;
    }

    case ArrayElement::OBJECT:
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