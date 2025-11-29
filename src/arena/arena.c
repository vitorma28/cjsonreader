#include "./arena.h"
#include <stdlib.h>


Arena * newArena(size_t size) {
    Arena * arena = (Arena *) malloc(sizeof(Arena *));
    void * memory = calloc(1, size);

    arena->begin = memory;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
