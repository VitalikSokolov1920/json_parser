#ifndef ARRAY_ELEMENT_HPP
#define ARRAY_ELEMENT_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <ostream>

class JsonElement
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
        std::vector<JsonElement> *arrayElem;
        std::unordered_map<std::string, JsonElement> *objectElem;
    };

private:
    JsonElement::TYPE type;

    JsonElement::Element elem;

public:
    JsonElement::Element &Elem()
    {
        return elem;
    }
    JsonElement() = default;
    JsonElement(const bool &);
    JsonElement(const int &);
    JsonElement(const double &);
    JsonElement(const std::string &);
    JsonElement(const std::vector<JsonElement> &);
    JsonElement(const std::unordered_map<std::string, JsonElement> &);
    friend std::ostream &operator<<(std::ostream &out, const JsonElement &elem);
};

#endif