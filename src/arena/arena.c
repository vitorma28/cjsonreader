#include "./arena.h"
#include <stdlib.h>


__CJR_Arena * __CJR_newArena(size_t size) {
    __CJR_Arena * arena = (__CJR_Arena *) malloc(sizeof(__CJR_Arena));

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
