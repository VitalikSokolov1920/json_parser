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

            ArrayParser parser(config);

            elem = parser.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

            goto finish;

            break;
        }
        case '{':
        {
            curlyBracketCounter++;

            strIter++;

            ObjectParser parser(config);

            elem = parser.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

            goto finish;

            break;
        }
        case ',':

            break;
        case '"':
        {
            strIter++;

            StringParser p(config);

            elem = p.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

            goto finish;

            break;
        }
        // true
        case 't':
        // false
        case 'f':
        {
            BoolParser p(config);

            elem = p.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

            goto finish;

            break;
        }
        case 'n':
        {
            NullParser p(config);

            elem = p.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

            goto finish;

            break;
        }
        case ':':
            break;

        // все неслужебные символы
        default:
            if (*strIter >= '0' && *strIter <= '9')
            {
                NumberParser p(config);

                elem = p.Parse(strIter, endIter, &squareBracketCounter, &curlyBracketCounter);

                goto finish;
            }
            break;
        }
    }

finish:
    return JSON::JSONDocument(elem);
}

JSON::JSONParser::JSONParser(const JSON::JSONFileReader &fileReader)
    : fileReader(fileReader), jsonString(""), inputType(FILE), AbstractParser(nullptr)
{
}

JSON::JSONParser::JSONParser(const std::string &jsonString)
    : jsonString(jsonString), inputType(STRING), AbstractParser(nullptr)
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

    if (inputType == FILE)
    {
        fileReader >> jsonString;
    }

    std::cout << "Input string: \n"
              << jsonString << std::endl;

    if (!config)
    {
        config = new Config(jsonString.cend(), jsonString.crend());
    }
    else
    {
        config->setAfterEnd(jsonString.cend());
        config->setBeforeBegin(jsonString.crend());
    }

    return JSON::JSONDocument(parseJsonString(jsonString));
}

JSON::JSONDocument JSON::JSONParser::nextToken()
{
    // TODO: переписать
    return JSON::JSONDocument(parseJsonString(jsonString));
}
