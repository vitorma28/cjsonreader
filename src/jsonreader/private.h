#ifndef PRIVATE_JSONREADER_H
#define PRIVATE_JSONREADER_H

#include "../arena/arena.h"
#include "../../libs/vector.h"


enum SymbolType {
    SPACE,
    OPEN_MAP,
    CLOSE_MAP,
    OPEN_ARR,
    CLOSE_ARR,
    ATTR_SEP,
    PAIR_VALUE_SEP,
    EDGE_STR,
    NUMBER,
    TEXT
};


typedef struct {
    char * value;
    enum SymbolType type;
} Symbol;


Vector * tokenizingBySymbols(CJR_Arena * arena, const char * text);

#endif