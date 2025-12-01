#include <stdlib.h>
#include "./arena.h"


__CJR_Arena * ArenaFrom(void * memory, size_t size) {
    __CJR_Arena * arena = (__CJR_Arena *) malloc(sizeof(__CJR_Arena));

    if (arena == NULL) {
        return NULL;
    }

    arena->begin = memory;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
