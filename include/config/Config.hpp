#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

namespace JSON
{
    class Config
    {
        /*
        TODO: подумать, какие опции добавить
        1. Выбрасывать исключение или возвращать ошибку в виде строки(или объекта)
        2. Установить количество байт, считывапемых при потоковом чтении
        3. Установить размер подстроки, которая содержит место, в котом котором произошла ошибка во время парсинга
        4. Путь к файлу для парсинга
        5. Путь к файлу для конфига
        6. Если произошла ошибка, пытаться продолжить парсинг, если это возможно
        */
        std::string::const_iterator afterEnd;
        std::string::const_reverse_iterator beforeBegin;

    public:
        Config(const std::string::const_iterator &afterEnd, const std::string::const_reverse_iterator &beforeBegin)
            : afterEnd(afterEnd),
              beforeBegin(beforeBegin) {}

        void setAfterEnd(const std::string::const_iterator &afterEnd)
        {
            this->afterEnd = afterEnd;
        }

        void setBeforeBegin(const std::string::const_reverse_iterator &beforeBegin)
        {
            this->beforeBegin = beforeBegin;
        }
    };
} // namespace JSON

#endif