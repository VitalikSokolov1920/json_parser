#include "JSONFileReader.hpp"
#include "JSONExceptions.hpp"

#include <iostream>

void JSON::JSONFileReader::openFile()
{
    inputFile.open(path, std::ios::in);

    if (!inputFile.is_open())
    {
        throw JSON::JSONException::InvalidOpenFileException(path);
    }
}

JSON::JSONFileReader::JSONFileReader(const std::string &path)
    : path(path)
{
    openFile();
}

JSON::JSONFileReader::JSONFileReader(const char *path)
    : JSONFileReader(std::string(path)) {}

JSON::JSONFileReader::JSONFileReader(const JSONFileReader &other)
    : JSONFileReader(other.path)
{
}

JSON::JSONFileReader::JSONFileReader() noexcept : path("") {}

JSON::JSONFileReader &JSON::JSONFileReader::operator=(const JSONFileReader &other)
{
    if (inputFile.is_open())
        inputFile.close();

    inputFile.open(other.path, std::ios::in);

    if (!inputFile.is_open())
    {
        throw JSON::JSONException::InvalidOpenFileException(path);
    }

    return *this;
}

size_t JSON::JSONFileReader::read(std::string &out, size_t max)
{
    char ch;
    size_t counter{0};

    if (max == 0)
    {
        while (true)
        {
            inputFile.get(ch);

            if (inputFile.eof())
            {
                break;
            }

            counter++;

            if (ch != '\n' && ch != '\r' && ch != ' ')
            {
                out += ch;
            }
        }
    }
    else
    {
        while (counter < max)
        {
            inputFile.get(ch);

            counter++;

            if (inputFile.eof())
            {
                break;
            }

            if (ch != '\n' && ch != ' ' && ch != '\r')
            {
                out += ch;
            }
        }
    }

    return counter;
}

const JSON::JSONFileReader &JSON::JSONFileReader::operator>>(std::string &out)
{
    read(out, 0);

    return *this;
}
