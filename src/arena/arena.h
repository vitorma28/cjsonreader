#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

#define KB(B) (B * 1024)

#define MB(B) KB(B * 1024)


// Struct principal

typedef struct {
    void * begin;
    size_t size;
    size_t offset;
} __CJR_Arena;


// Funções

__CJR_Arena * __CJR_newArena(size_t size);

__CJR_Arena * __CJR_ArenaFrom(void * memory, size_t size);

void * __CJR_ArenaAlloc(__CJR_Arena * arena, size_t size_to_alloc);

void __CJR_ArenaReset(__CJR_Arena * arena);

void __CJR_ArenaDestroy(__CJR_Arena * arena);

void __CJR_ArenaAutoDestroy(__CJR_Arena ** arena);

void * __CJR_ArenaRealloc(__CJR_Arena * arena, void * oldPtr, size_t oldSize, size_t newSize);

#endif
