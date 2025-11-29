#include "./arena.h"


Arena * newArena(size_t size) {
    Arena * arena = (Arena *) malloc(sizeof(Arena *));
    void * memory = malloc(size);

    arena->begin = memory;
    arena->end = memory + size - 1;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
