#include <vector>

#include <iostream>

#include "parsers/ArrayParser.hpp"
#include "parsers/NumberParser.hpp"
#include "parsers/StringParser.hpp"
#include "parsers/BoolParser.hpp"
#include "parsers/ObjectParser.hpp"
#include "parsers/NullParser.hpp"

JSON::JsonElement JSON::ArrayParser::Parse(
    std::string::const_iterator &begin,
    std::string::const_iterator &end,
    int *squareBracketCounter,
    int *curlyBracketCounter)
{
    std::vector<JsonElement> array;

    while (begin < end)
    {
        // TODO: переписать
        // if (*begin == ']')
        // {
        //     if (squareBracketCounter)
        //         *squareBracketCounter--;

        //     return array;
        // }

        switch (*begin)
        {
        // true
        case 't':
        // false
        case 'f':
        {
            BoolParser parser(config);

            auto elem = parser.Parse(begin, end);

            array.push_back(elem);

            break;
        }

        case 'n':
        {
            NullParser p(config);

            auto elem = p.Parse(begin, end);

            array.push_back(elem);

            break;
        }

        case '"':
        {
            begin++;

            StringParser parser(config);

            auto strStr = parser.Parse(begin, end);

            JsonElement str(strStr);

            array.push_back(str);

            break;
        }

        case '[':
        {
            begin++;

            ArrayParser parser(config);

            // TODO: подумать, что передавать в качестве счётчика [ (innerSquareBracketCounter или squareBracketCounter)
            auto arrayElem = parser.Parse(begin, end);

            array.push_back(arrayElem);

            break;
        }

        case '{':
        {
            begin++;

            ObjectParser parser(config);

            auto elem = parser.Parse(begin, end);

            array.push_back(elem);

            break;
        }

        case ']':
        {
            begin++;

            return array;
        }

        default:
        {
            if (*begin >= '0' && *begin <= '9')
            {
                NumberParser numParser(config);

                auto number = numParser.Parse(begin, end, squareBracketCounter);

                array.push_back(number);
            }
            else
            {
                begin++;
            }
            break;
        }
        }
    }

    return JsonElement(array);
}
