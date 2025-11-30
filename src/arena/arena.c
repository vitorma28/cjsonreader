#include "./arena.h"
#include <stdlib.h>


Arena * newArena(size_t size) {
    Arena * arena = (Arena *) malloc(sizeof(Arena *));

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
