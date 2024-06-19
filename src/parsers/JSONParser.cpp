#include "JSONExceptions.hpp"

#include "parsers/JSONParser.hpp"
#include "parsers/ArrayParser.hpp"
#include "parsers/ObjectParser.hpp"

#include <iostream>

JSON::JSONDocument JSON::JSONParser::parseJsonString(const std::string &input)
{
    std::string::const_iterator strIter(input.cbegin()), endIter(input.cend());
    int squareBracketCounter = 0, curlyBracketCounter = 0;

    for (; strIter < endIter; strIter++)
    {
        switch (*strIter)
        {
        case '[':
        {
            squareBracketCounter++;

            strIter++;

            ArrayParser parser;

            auto result = parser.Parse(strIter, endIter, &squareBracketCounter);

            std::cout << result << std::endl;

            break;
        }
        case '{':
        {
            curlyBracketCounter++;

            strIter++;

            ObjectParser parser;

            auto result = parser.Parse(strIter, endIter);

            std::cout << result << std::endl;

            break;
        }
        case ',':

            break;
        case '"':

            break;
        // true
        case 't':
            break;
        // false
        case 'f':
            break;
        case ':':

            break;

        // все неслужебные символы
        default:
            break;
        }
    }

    return JSON::JSONDocument();
}

JSON::JSONParser::JSONParser(const JSON::JSONFileReader &fileReader)
    : fileReader(fileReader), jsonString(""), inputType(FILE)
{
}

JSON::JSONParser::JSONParser(const std::string &jsonString)
    : jsonString(jsonString), inputType(STRING)
{
}

void JSON::JSONParser::setFileReader(const JSON::JSONFileReader &fileReader)
{
    this->fileReader = fileReader;
    inputType = FILE;
}

void JSON::JSONParser::setJSONString(const std::string &jsonString)
{
    this->jsonString = jsonString;
    inputType = STRING;
}

JSON::JSONDocument JSON::JSONParser::parse()
{
    if (!fileReader.isOpen())
    {
        throw JSON::JSONException::InvalidOpenFileException("File is not open");
    }

    // JSON::JSONDocument result;

    switch (inputType)
    {
    case FILE:
    {
        std::string input;

        fileReader >> input;

        std::cout << input;
        std::cout << std::endl;

        parseJsonString(input);

        break;
    }
    case STRING:
    {
        break;
    }
    default:
        break;
    }

    return JSON::JSONDocument();
}

JSON::JSONDocument JSON::JSONParser::nextToken()
{
    return JSON::JSONDocument();
}
