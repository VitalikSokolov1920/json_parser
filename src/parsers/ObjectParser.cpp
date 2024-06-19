#include <iostream>

#include "parsers/ObjectParser.hpp"
#include "parsers/StringParser.hpp"
#include "parsers/ArrayParser.hpp"
#include "parsers/NumberParser.hpp"
#include "parsers/BoolParser.hpp"

ArrayElement ObjectParser::Parse(std::string::const_iterator &begin,
                                 std::string::const_iterator &end,
                                 int *, int *)
{
    std::unordered_map<std::string, ArrayElement> object;
    bool hasFieldName = false;
    std::string curFieldName{""};

    while (begin < end)
    {
        switch (*begin)
        {
            // true
        case 't':
        // false
        case 'f':
        {
            if (!hasFieldName)
            {
                // TODO: обработать ошибку
                begin++;
                continue;
            }
            BoolParser parser;

            auto elem = parser.Parse(begin, end);

            object[curFieldName] = elem;

            hasFieldName = false;

            break;
        }
        case '"':
        {
            begin++;

            StringParser parser;

            auto elem = parser.Parse(begin, end);
            // парсим значение
            if (hasFieldName)
            {
                object[curFieldName] = elem;

                hasFieldName = false;
            }
            else // парсим имя свойства
            {
                curFieldName = *elem.Elem().strElem;
                hasFieldName = true;
            }

            break;
        }
        case '[':
        {
            begin++;

            if (!hasFieldName)
            {
                // TODO: обработать ошибку
                continue;
            }

            ArrayParser parser;

            auto elem = parser.Parse(begin, end);

            object[curFieldName] = elem;

            hasFieldName = false;

            break;
        }
        case '{':
        {
            begin++;

            if (!hasFieldName)
            {
                // TODO: обработать ошибку
                continue;
            }
            ObjectParser parser;

            auto elem = parser.Parse(begin, end);

            object[curFieldName] = elem;

            break;
        }
        case '}':
            begin++;

            return object;
        default:
            if (*begin >= '0' && *begin <= '9')
            {
                if (!hasFieldName)
                {
                    // TODO: обработать ошибку
                    begin++;
                    continue;
                }
                NumberParser parser;

                auto elem = parser.Parse(begin, end);

                object[curFieldName] = elem;

                hasFieldName = false;
            }
            else
            {
                begin++;
            }
            break;
        }
    }

    return object;
}