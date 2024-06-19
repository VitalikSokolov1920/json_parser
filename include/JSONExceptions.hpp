#ifndef JSONEXCEPTIONS_HPP
#define JSONEXCEPTIONS_HPP

#include <exception>
#include <string>

namespace JSON
{
    namespace JSONException
    {
        class InvalidOpenFileException : std::exception {
            std::string path;
        public:
            InvalidOpenFileException(const std::string&);
            InvalidOpenFileException(const char*);
            const char* what() const noexcept;
        };

        class EOFileException : std::exception {

        };
    } // namespace JSONException
    
} // namespace JSON

#endif