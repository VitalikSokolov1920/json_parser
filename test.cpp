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
        std::cout << "\n\n\nResult: " << result[0][10]["b"][0].toString() << std::endl;
    }
    catch (const JSON::JSONException::BaseException &e)
    {
        std::cerr << e.what() << std::endl;

        return -1;
    }
    catch (const JSON::JSONException::UnsupportedConvertion &e)
    {
        std::cerr << e.what() << std::endl;

        return -1;
    }
    catch (const JSON::JSONException::IndexOutOfRange &e)
    {
        std::cerr << e.what() << std::endl;

        return -1;
    }
    catch (const JSON::JSONException::PropertyNotExist &e)
    {
        std::cerr << e.what() << std::endl;

        return -1;
    }

    return 0;
}