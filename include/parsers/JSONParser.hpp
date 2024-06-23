#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

/*
Какие могут быть входные данные:
1. массив примитивов(int[], float[], string[])
[1,2,3]
или
["hello", "world"]
2. массив объектов(object[])
[
    {
        "number": 1,
        "string": "hello world"
    },
    {
        "number": 2,
        "string": "hello world"
    }
]
3. объект({"name": "value"})
{
    "number": 1,
    "string": "hello world",
    "array": [
        1,2,3
    ],
    "array2": [
        "string1", "string2"
    ],
    "array3": [
        {
            "key": value
        },
        {
            "key2": value
        },
    ]
}
4. массив массивов
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
*/

#include "JSONFileReader.hpp"
#include "JSONResult.hpp"
#include "parsers/AbstractParser.hpp"
#include "config/Config.hpp"

namespace JSON
{
    class JSONParser : AbstractParser
    {
        enum SOURCE_TYPE
        {
            FILE,
            STRING
        };
        JSON::JSONFileReader fileReader;
        std::string jsonString;
        JSONParser::SOURCE_TYPE inputType;

        JSON::JSONDocument parseJsonString(const std::string &input);
        JsonElement Parse(std::string::const_iterator &, std::string::const_iterator &, int * = nullptr, int * = nullptr)
        {
            return JsonElement(nullptr);
        }

    public:
        JSONParser(const JSON::JSONFileReader &);
        JSONParser(const std::string &);
        void setFileReader(const JSON::JSONFileReader &);
        void setJSONString(const std::string &);
        JSON::JSONDocument parse();
        JSON::JSONDocument nextToken();
        bool hasNext() const
        {
            return !fileReader.eof();
        }
    };
} // namespace JSON

#endif