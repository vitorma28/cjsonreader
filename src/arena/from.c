#include <stdlib.h>
#include "./arena.h"


Arena * ArenaFrom(void * memory, size_t size) {
    Arena * arena = (Arena *) malloc(sizeof(Arena));

    if (arena == NULL) {
        return NULL;
    }

    arena->begin = memory;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
