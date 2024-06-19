#ifndef ARRAY_ELEMENT_HPP
#define ARRAY_ELEMENT_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <ostream>

class ArrayElement
{
public:
    enum TYPE
    {
        BOOL,
        INT,
        DOUBLE,
        STRING,
        ARRAY,
        OBJECT
    };

    union Element
    {
        bool *boolElem;
        int *intElem;
        double *doubleElem;
        std::string *strElem;
        std::vector<ArrayElement> *arrayElem;
        std::unordered_map<std::string, ArrayElement> *objectElem;
    };

private:
    ArrayElement::TYPE type;

    ArrayElement::Element elem;

public:
    ArrayElement::Element &Elem()
    {
        return elem;
    }
    ArrayElement() = default;
    ArrayElement(const bool &);
    ArrayElement(const int &);
    ArrayElement(const double &);
    ArrayElement(const std::string &);
    ArrayElement(const std::vector<ArrayElement> &);
    ArrayElement(const std::unordered_map<std::string, ArrayElement> &);
    friend std::ostream &operator<<(std::ostream &out, const ArrayElement &elem);
};

#endif