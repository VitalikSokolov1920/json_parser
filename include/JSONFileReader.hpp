#ifndef JSONREADER_HPP
#define JSONREADER_HPP

#include <string>
#include <fstream>

namespace JSON
{
    class JSONFileReader {
        std::ifstream inputFile;
        std::string path;
        void openFile();
    public:
        JSONFileReader(const std::string&);
        JSONFileReader(const char*);
        JSONFileReader(const JSONFileReader&);
        JSONFileReader() noexcept;
        JSONFileReader& operator=(const JSONFileReader&);
        size_t read(std::string& out, size_t max = 0);
        bool isOpen() const {
            return inputFile.is_open();
        }
        bool eof() const {
            return inputFile.eof();
        }
        const JSONFileReader& operator>>(std::string&);
    };
} // namespace JSON


#endif