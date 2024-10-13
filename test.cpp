#include <iostream>

#include "parsers/JSONParser.hpp"
#include "JSONExceptions.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Expected path to JSON file. Return\n";

        exit(EXIT_FAILURE);
    }

    JSON::JSONFileReader fr(argv[1]);

    std::string json;

    fr >> json;

    JSON::JSONParser parser(json);

    auto result = parser.parse();

    auto value = result["file_path"].toString();

    std::cout << "File path prop: " << value << std::endl;

    // if (value)
    // {
    //     std::cout << "Result: " << value.value() + 200 << " (success convertion)" << std::endl;
    // }
    // else
    // {
    //     std::cout << "failed conversion";
    // }
    // catch (const JSON::JSONException::UnsupportedConvertion &e)
    // {
    //     std::cerr << e.what() << std::endl;

    //     return -1;
    // }
    // catch (const JSON::JSONException::IndexOutOfRange &e)
    // {
    //     std::cerr << e.what() << std::endl;

    //     return -1;
    // }
    // catch (const JSON::JSONException::PropertyNotExist &e)
    // {
    //     std::cerr << e.what() << std::endl;

    //     return -1;
    // }

    return 0;
}