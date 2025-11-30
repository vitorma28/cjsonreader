#include "./arena.h"
#include <string.h>


void * ArenaRealloc(Arena * arena, void * oldPtr, size_t oldSize, size_t newSize) {
    if (newSize == 0) return NULL;

    void * newPtr = ArenaAlloc(arena, newSize);

    size_t sizeToRealloc = oldSize > newSize ? newSize : oldSize;

    memcpy(newPtr, oldPtr, sizeToRealloc);

    return newPtr;
}
