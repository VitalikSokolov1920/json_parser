#include "parsers/NullParser.hpp"

JsonElement NullParser::Parse(std::string::const_iterator &begin, std::string::const_iterator &end, int *, int *)
{
    char prev;
    short lSymbolCounter = 0;

    while (begin < end)
    {
        switch (*begin)
        {
        case 'n':
            prev = *begin;
            break;

        case 'u':
            if (prev == 'n')
            {
                prev = *begin;

                break;
            }
            goto error;

        case 'l':
            // null
            if (prev == 'u' && !lSymbolCounter)
            {
                lSymbolCounter++;
                prev = *begin;
            }
            else if (prev == 'l' && lSymbolCounter == 1)
            {
                return JsonElement(nullptr);
            }
            else
            {
                goto error;
            }
            break;

        default:
            goto error;
            break;
        }
        begin++;
    }

error:
    // TODO: добавить установку ошибки
    return JsonElement(nullptr);
}