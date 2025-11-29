#include <stddef.h>


enum JSTypes {
    STRING,
    NUMBER,
    BOOLEAN,
    OBJECT,
    ARRAY,
    JSNULL
};


typedef struct {
    enum JSTypes type;
    void * value;
} Value;


typedef struct {
    char * key;
    Value value;
} MapEntry;


typedef struct {
    MapEntry * entries;
    size_t length;
    size_t maxLength;
} Map;


Map * newMap();

