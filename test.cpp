#include <iostream>

#include "parsers/JSONParser.hpp"
#include "JSONExceptions.hpp"

int main(int argc, char *argv[])
{
    JSON::JSONFileReader fr("./test.json");

    std::string json;

    fr >> json;

    JSON::JSONParser parser(json);

    auto result = parser.parse();

    try
    {
        std::cout << result.toBool() << std::endl;
    }
    catch (const JSON::JSONException::UnsupportedConvertion &e)
    {
        std::cerr << e.what() << std::endl;

        return -1;
    }

    return 0;
}