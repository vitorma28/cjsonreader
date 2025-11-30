#ifndef MAP_H
#define MAP_H

#include <stddef.h>
#include "../arena/arena.h"


typedef enum {
    STRING,
    NUMBER,
    BOOLEAN,
    OBJECT,
    ARRAY,
    JSNULL
} JSTypes;


typedef struct {
    JSTypes type;
    void * value;
} Value;


typedef struct {
    char * key;
    Value * value;
} MapEntry;


typedef struct {
    MapEntry * entries;
    size_t length;
    size_t maxLength;
} Map;


Map * newMap(Arena * arena);
Value * MapGet(Map * map, char * key);

MapEntry * newMapEntry(Arena * arena, char * key, Value * value);

Value * newValue(Arena * arena, JSTypes dataType, void * dataValue);


#endif
