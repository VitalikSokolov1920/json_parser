TARGET_PREFIX=libjsonparser.

ifeq ($(OS), Windows_NT)
	TARGET=$(TARGET_PREFIX)dll
	DEL_CMD=del
	SOURCES=src\parsers\JSONParser.o \
		src\JSONFileReader.o \
		src\JSONExceptions.o \
		src\JSONResult.o \
		src\base_elements\JsonElement.o \
		src\parsers\AbstractParser.o \
		src\parsers\ArrayParser.o \
		src\parsers\NumberParser.o \
		src\parsers\StringParser.o \
		src\parsers\ObjectParser.o \
		src\parsers\BoolParser.o
else
	TARGET=$(TARGET_PREFIX)so
	DEL_CMD=rm -f
	SOURCES=src/parsers/JSONParser.o \
		src/JSONFileReader.o \
		src/JSONExceptions.o \
		src/JSONResult.o \
		src/base_elements/JsonElement.o \
		src/parsers/AbstractParser.o \
		src/parsers/ArrayParser.o \
		src/parsers/NumberParser.o \
		src/parsers/StringParser.o \
		src/parsers/ObjectParser.o \
		src/parsers/BoolParser.o
endif

LDFLAGS=-shared -ggdb -g -O0 -Werror
CPPFLAGS=-Iinclude -DDEBUG -ggdb -g -fPIC -O0 -Werror
CC=g++

.PHONY: all clean clean_all

all: clean_all $(SOURCES)
	$(CC) $(LDFLAGS) $(SOURCES) -o $(TARGET)

test: all
	$(CC) test.cpp -o test -L. -ljsonparser -Iinclude

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean_all: clean
	$(DEL_CMD) $(TARGET)

clean:
	$(DEL_CMD) $(SOURCES)
