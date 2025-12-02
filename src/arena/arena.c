#include "private.h"
#include "./arena.h"
#include <stdlib.h>


CJR_Arena * CJR_newArena(size_t size) {
    CJR_Arena * arena = (CJR_Arena *) malloc(sizeof(CJR_Arena));

    if (arena == NULL) {
        return NULL;
    }

    void * memory = calloc(1, size);

    if (memory == NULL) {
        return NULL;
    }

    arena->begin = memory;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
