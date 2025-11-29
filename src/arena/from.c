#include "./arena.h"


Arena * ArenaFrom(const void * memory, size_t size) {
    Arena * arena = (Arena *) malloc(sizeof(Arena *));

    arena->begin = memory;
    arena->end = memory + size - 1;
    arena->size = size;
    arena->offset = 0;

    return arena;
}
