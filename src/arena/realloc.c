#include "./arena.h"
#include <string.h>


void * __CJR_ArenaRealloc(__CJR_Arena * arena, void * oldPtr, size_t oldSize, size_t newSize) {
    if (newSize == 0) return NULL;

    void * newPtr = __CJR_ArenaAlloc(arena, newSize);

    size_t sizeToRealloc = oldSize > newSize ? newSize : oldSize;

    memcpy(newPtr, oldPtr, sizeToRealloc);

    return newPtr;
}
