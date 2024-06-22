#include "parsers/BoolParser.hpp"

JSON::JsonElement JSON::BoolParser::Parse(std::string::const_iterator &begin, std::string::const_iterator &end, int *, int *)
{
    bool result = false, needBreak = false;
    char prev = 0;

    while (begin < end)
    {
        if (needBreak)
        {
            break;
        }
        switch (*begin)
        {
        case 't':
            prev = *begin;
            break;
        case 'r':
            // TODO: подумать, как обощить на все буквы
            if (prev == 't')
            {
                prev = *begin;
            }
            else
            {
                goto error;
                break;
            }
            break;
        case 'u':
            if (prev == 'r')
            {
                prev = *begin;
            }
            else
            {
                goto error;
                break;
            }
            break;
        case 'e':
            if (prev == 'u')
            {
                result = true;
                needBreak = true;
            }
            else if (prev = 's')
            {
                result = false;
                needBreak = true;
            }
            else
            {
                goto error;
                break;
            }
            break;
        case 'f':
            prev = *begin;
            break;
        case 'a':
            if (prev == 'f')
            {
                prev = *begin;
            }
            else
            {
                goto error;
                break;
            }
            break;
        case 'l':
            if (prev == 'a')
            {
                prev = *begin;
            }
            else
            {
                goto error;
                break;
            }
            break;
        case 's':
            if (prev == 'l')
            {
                prev = *begin;
            }
            else
            {
                goto error;
                break;
            }
            break;
        default:
            // ошибка парсинга
            goto error;
            break;
        }
        begin++;
    }

error:
    // TODO: выдать ошибку
    return result;
}