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
        const JsonElement::Element &Elem() const
        {
            return elem;
        }
        JsonElement() = default;
        JsonElement(const bool &);
        JsonElement(const int &);
        JsonElement(const double &);
        JsonElement(const std::string &);
        JsonElement(const char &);
        JsonElement(const std::vector<JsonElement> &);
        JsonElement(const std::unordered_map<std::string, JsonElement> &);
        JsonElement(void *);
        JsonElement(const JsonElement &);
        std::string toString() const;
        JsonElement &operator=(const JsonElement &);
        friend std::ostream &operator<<(std::ostream &out, const JSON::JsonElement &elem);
        virtual ~JsonElement();
        TYPE Type() const
        {
            return type;
        }
    };
}

#endif