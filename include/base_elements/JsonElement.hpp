#ifndef ARRAY_ELEMENT_HPP
#define ARRAY_ELEMENT_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <ostream>

namespace JSON
{
    class JsonElement
    {
    public:
        enum TYPE
        {
            NOT_SET,
            BOOL,
            INT,
            DOUBLE,
            STRING,
            ARRAY,
            OBJECT,
            JSON_NULL,
        };

        union Element
        {
            bool *boolElem;
            int *intElem;
            double *doubleElem;
            std::string *strElem;
            std::vector<JsonElement> *arrayElem;
            std::unordered_map<std::string, JsonElement> *objectElem;
            void *null;
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
        JsonElement(void *);
        JsonElement(const JsonElement &);
        JsonElement &operator=(const JsonElement &);
        friend std::ostream &operator<<(std::ostream &out, const JSON::JsonElement &elem);
        virtual ~JsonElement();
    };
}

#endif