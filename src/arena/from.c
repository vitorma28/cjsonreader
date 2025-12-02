#include "private.h"
#include <stdlib.h>
#include "./arena.h"


CJR_Arena * CJR_ArenaFrom(void * memory, size_t size) {
    CJR_Arena * arena = (CJR_Arena *) malloc(sizeof(CJR_Arena));

    if (arena == NULL) {
        return NULL;
    }

    arena->begin = memory;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
