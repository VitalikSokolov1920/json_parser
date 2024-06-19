#ifndef JSONRESULT_HPP
#define JSONRESULT_HPP

#include <cstddef>
#include <string>

namespace JSON
{
    class Filed
    {
    };

    class JSONDocument
    {
    public:
        JSONDocument() = default;
        int &operator[](std::string filed);
        // virtual void setArrayValue(std::string fieldName, std::vector<long long> vec) = 0;
        // virtual void setArrayValue(std::string fieldName, std::vector<double> vec) = 0;
        /*
        сделать оператор индексирования чисто виртуальной функцией,
        и присваивать значения полям через передачу строки, как индекса, и значение
        пример: object["filed"] = "string"
        подумать над перегрузкой для разных типов данных(числа, строки, массивы, объекты)
        */
    };
} // namespace JSON

#endif