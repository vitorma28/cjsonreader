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
} __CJR_JSTypes;


typedef struct {
    __CJR_JSTypes type;
    void * value;
} __CJR_Value;


typedef struct {
    char * key;
    __CJR_Value * value;
} __CJR_MapEntry;


typedef struct {
    __CJR_MapEntry * entries;
    size_t length;
    size_t maxLength;
} __CJR_Map;


__CJR_Map * __CJR_newMap(Arena * arena, size_t maxLength);
__CJR_Value * __CJR_MapGet(__CJR_Map * map, char * key);
__CJR_Map * __CJR_MapSet(Arena * arena, __CJR_Map * map, char * key, __CJR_Value * value);

__CJR_MapEntry __CJR_newMapEntry(char * key, __CJR_Value * value);

__CJR_Value * __CJR_newValue(Arena * arena, __CJR_JSTypes dataType, void * dataValue);


#endif
