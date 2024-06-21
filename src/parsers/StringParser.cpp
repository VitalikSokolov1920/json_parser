#include "parsers/StringParser.hpp"

JsonElement StringParser::Parse(std::string::const_iterator &begin, std::string::const_iterator &end, int *, int *)
{
    std::string strStr;

    while (begin < end)
    {
        if (*begin == '"')
        {
            break;
        }

        if (*begin == ',' || *begin == ']' || *begin == '}')
        {
            // Ошибка
        }
        strStr += *begin;
        begin++;
    }

    begin++;

    return strStr;
}