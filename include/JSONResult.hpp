#ifndef JSONRESULT_HPP
#define JSONRESULT_HPP

#include <cstddef>
#include <string>

#include "base_elements/JsonElement.hpp"

namespace JSON
{
    class JSONDocument
    {
        JsonElement elem;

    public:
        JSONDocument(const JsonElement &elem) : elem(elem) {}
        // для получения значения свойства объекта
        JSONDocument operator[](std::string);
        JSONDocument operator[](int);
        std::string toString();
        int toInt();
        double toDouble();
        bool toBool();
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