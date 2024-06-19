#include <cstring>

#include "JSONExceptions.hpp"

JSON::JSONException::InvalidOpenFileException::InvalidOpenFileException(const std::string& path) : path(path) {}

JSON::JSONException::InvalidOpenFileException::InvalidOpenFileException(const char* path) : path(path) {}

const char* JSON::JSONException::InvalidOpenFileException::what() const noexcept {
    std::string out {"Can't open file "};
    out += path;
    return out.c_str();
}