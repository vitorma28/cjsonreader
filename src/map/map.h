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
} CJR_JSTypes;


typedef struct CJR_Value CJR_Value;


typedef struct CJR_MapEntry CJR_MapEntry;


typedef struct CJR_Map CJR_Map;


CJR_Map * CJR_newMap(CJR_Arena * arena, size_t maxLength);
CJR_Value * CJR_MapGet(CJR_Map * map, char * key);
CJR_Map * CJR_MapSet(CJR_Arena * arena, CJR_Map * map, char * key, CJR_Value * value);

CJR_MapEntry CJR_newMapEntry(char * key, CJR_Value * value);

CJR_Value * CJR_newValue(CJR_Arena * arena, CJR_JSTypes dataType, void * dataValue);


#endif
