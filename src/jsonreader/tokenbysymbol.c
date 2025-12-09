/*
Níveis de tokenização:

{"teste": 10}

1.: Separar por caracteres | AUTOMÁTICO

Lista de caracteres normais.

{,",t,e,s,t,e,",:, ,1,0,}


2.: Separar por símbolos

SYMBOLS:

Os VALUE aqui são NULL.

' ' -> SPACE

{ -> OPEN_MAP
} -> CLOSE_MAP

[ -> OPEN_ARR
] -> CLOSE_ARR

: -> ATTR_SEP
, -> PAIR_SEP
inner array:
    , -> VALUE_SEP

" -> OPEN/CLOSE _STR

Já aqui possui um value.

0-9+ -> NUMBER

anything else -> TEXT



*/

#include "private.h"

#include <string.h>
#include <stdio.h>


Symbol * newSymbol(CJR_Arena * arena, enum SymbolType type, char * value) {
    Symbol * sym = (Symbol *) CJR_ArenaAlloc(arena, sizeof(Symbol));

    sym->type = type;
    sym->value = value;

    return sym;
}


void * allocate(size_t size, const void * context) {
    return CJR_ArenaAlloc((CJR_Arena *) context, size);
}


void liberate(void * ptr, const void * context) {
    // nothing, unable to free memory with bump allocator.
}


static bool isSpace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}


static bool isNumber(char ch) {
    return ch >= '0' && ch <= '9';
}

static bool isNotTEXT(char ch) {
    return isSpace(ch) || isNumber(ch) || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '"' || ch == ':' || ch == ',';
}


Vector * tokenizingBySymbols(CJR_Arena * arena, const char * text) {
    Vector * symbols = VectorInit(0, sizeof(Symbol), arena, allocate, liberate);

    if (symbols == NULL) return NULL;

    size_t textLen = strlen(text);

    for (size_t i = 0; i < textLen; i++) {
        char ch = text[i];

        printf("'%c'\n", ch);

        bool simpleSymbol = false;
        enum SymbolType type;

        if (isSpace(ch)) {
            simpleSymbol = true;
            type = SPACE;
        }

        if (!simpleSymbol)
        switch (ch) {
            case '{': {
                simpleSymbol = true;
                type = OPEN_MAP;

                break;
            }
            case '}': {
                simpleSymbol = true;
                type = CLOSE_MAP;

                break;
            }
            case '[': {
                simpleSymbol = true;
                type = OPEN_ARR;

                break;
            }
            case ']': {
                simpleSymbol = true;
                type = CLOSE_ARR;

                break;
            }
            case ':': {
                simpleSymbol = true;
                type = ATTR_SEP;

                break;
            }
            case ',': {
                simpleSymbol = true;
                type = PAIR_VALUE_SEP;

                break;
            }
            case '"': {
                simpleSymbol = true;
                type = EDGE_STR;

                break;
            }
        }

        if (simpleSymbol) {
            printf("Was a simple symbol. %d.\n", type);
            VectorPush(symbols, newSymbol(arena, type, NULL));
            printf("Current length: %zu.\n", VectorLength(symbols));
            Symbol * lastSym = (Symbol *) VectorGet(symbols, VectorLength(symbols) - 1);
            printf("Symbol added: T: %d, V: %c.\n", lastSym->type, lastSym->value == NULL ? 'N' : 'V');

            continue;
        }

        if (isNumber(ch)) {
            size_t numberSize = 0;

            for (size_t j = i; text[j] && isNumber(text[j]); j++) numberSize++;

            char * string = (char *) CJR_ArenaAlloc(arena, numberSize + 1);

            memcpy(string, text + i, numberSize);
            string[numberSize] = '\0';

            VectorPush(symbols, newSymbol(arena, NUMBER, string));

            i += numberSize - 1;

            continue;
        }


        size_t textSize = 0;

        for (size_t j = i; text[j] && !isNotTEXT(text[j]); j++) textSize++;

        char * string = (char *) CJR_ArenaAlloc(arena, textSize + 1);

        memcpy(string, text + i, textSize);
        string[textSize] = '\0';

        VectorPush(symbols, newSymbol(arena, TEXT, string));

        i += textSize - 1;
    }

    return symbols;
}
