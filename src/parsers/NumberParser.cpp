#ifdef DEBUG
#include <iostream>
#endif

#include "parsers/NumberParser.hpp"

NumberParser::NumberParser()
{
}

ArrayElement NumberParser::Parse(std::string::const_iterator &begin, std::string::const_iterator &end, int *, int *)
{
    if (*begin >= '0' && (*begin) <= '9')
    {
        std::string numberStr;

        bool isFloat = false, hasComma = false;

        while (begin < end)
        {
            if (*begin == ',')
            {
                hasComma = true;
                break;
            }
            if (*begin == ']' || *begin == '}')
            {
                // TODO: обработать ошибку

                break;
            }

            numberStr += *begin;

            if (*begin == '.')
            {
                if (isFloat)
                {
                    // TODO: обработать ошибку
                }
                isFloat = true;
            }
            begin++;
        }

        if (!hasComma)
        {
            // TODO: обработать ошибку
        }

        if (isFloat)
        {
            return ArrayElement(::atof(numberStr.c_str()));
        }

        return ArrayElement(::atoi(numberStr.c_str()));

        // TODO: возможно, нужно убрать
        // if (*begin == ']')
        // {
        //     if (squareBracketCounter)
        //         *squareBracketCounter--;
        // }

        // array.push_back(::atof(numberStr.c_str()));
    }
    else
    {
        // TODO: обработать ошибку
        return ArrayElement(0);
    }
}
