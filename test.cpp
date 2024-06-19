#include <iostream>

#include "parsers/JSONParser.hpp"

int main(int argc, char *argv[])
{
    JSON::JSONFileReader fr("./test.json");

    JSON::JSONParser parser(fr);

    auto result = parser.parse();

    return 0;
}