#include "JSONExceptions.hpp"

#include "parsers/JSONParser.hpp"
#include "parsers/ArrayParser.hpp"
#include "parsers/ObjectParser.hpp"
#include "parsers/StringParser.hpp"
#include "parsers/BoolParser.hpp"
#include "parsers/NumberParser.hpp"
#include "parsers/NullParser.hpp"

#include <iostream>

JSON::JSONDocument JSON::JSONParser::parseJsonString(const std::string &input)
{
    std::string::const_iterator strIter(input.cbegin()), endIter(input.cend());
    int squareBracketCounter = 0, curlyBracketCounter = 0;
    JsonElement elem;

    for (; strIter < endIter; strIter++)
    {
        switch (*strIter)
        {
        case '[':
        {
            squareBracketCounter++;

            strIter++;

            ArrayParser parser;

            elem = parser.Parse(strIter, endIter, &squareBracketCounter);

            break;
        }
        case '{':
        {
            curlyBracketCounter++;

            strIter++;

            ObjectParser parser;

            elem = parser.Parse(strIter, endIter);

            break;
        }
        case ',':

            break;
        case '"':
        {
            strIter++;

            StringParser p;

            elem = p.Parse(strIter, endIter);

            break;
        }
        // true
        case 't':
        // false
        case 'f':
        {
            BoolParser p;

            elem = p.Parse(strIter, endIter);

            break;
        }
        case 'n':
        {
            NullParser p;

            elem = p.Parse(strIter, endIter);

            break;
        }
        case ':':
            break;

        // все неслужебные символы
        default:
            if (*strIter >= '0' && *strIter <= '9')
            {
                NumberParser p;

                elem = p.Parse(strIter, endIter);
            }
            break;
        }
    }

    return JSON::JSONDocument(elem);
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
    if (inputType == FILE && !fileReader.isOpen())
    {
        throw JSON::JSONException::InvalidOpenFileException("File is not open");
    }

    switch (inputType)
    {
    case FILE:
    {
        std::string input;

        fileReader >> input;

        std::cout << "Input string: \n"
                  << input << std::endl;

        return JSON::JSONDocument(parseJsonString(input));

        break;
    }
    case STRING:
    {
        std::cout << "Input string: \n"
                  << jsonString << std::endl;

        return JSON::JSONDocument(parseJsonString(jsonString));

        break;
    }
    default:
        return JSON::JSONDocument(parseJsonString(jsonString));
        break;
    }
}

JSON::JSONDocument JSON::JSONParser::nextToken()
{
    // TODO: переписать
    return JSON::JSONDocument(parseJsonString(jsonString));
}
