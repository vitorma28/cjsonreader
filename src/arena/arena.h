#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

#define KB(B) (B * 1024)

#define MB(B) KB(B * 1024)


// Struct principal

typedef struct CJR_Arena CJR_Arena;


// Funções

CJR_Arena * CJR_newArena(size_t size);

CJR_Arena * CJR_ArenaFrom(void * memory, size_t size);

void * CJR_ArenaAlloc(CJR_Arena * arena, size_t size_to_alloc);

void CJR_ArenaReset(CJR_Arena * arena);

void CJR_ArenaDestroy(CJR_Arena * arena);

void CJR_ArenaAutoDestroy(CJR_Arena ** arena);

void * CJR_ArenaRealloc(CJR_Arena * arena, void * oldPtr, size_t oldSize, size_t newSize);

#endif
