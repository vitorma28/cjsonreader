#ifndef PRIVATE_MAP_H
#define PRIVATE_MAP_H

#include <stddef.h>


typedef enum {
    STRING,
    NUMBER,
    BOOLEAN,
    OBJECT,
    ARRAY,
    JSNULL
} CJR_JSTypes;


struct CJR_Value {
    CJR_JSTypes type;
    void * value;
};


struct CJR_MapEntry {
    char * key;
    struct CJR_Value * value;
};


struct CJR_Map {
    struct CJR_MapEntry * entries;
    size_t length;
    size_t maxLength;
};


#endif