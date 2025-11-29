#include <stddef.h>

#define KB(B) (B * 1024)

#define MB(B) KB(B * 1024)


// Struct principal

typedef struct {
    const void * begin;
    size_t size;
    size_t offset;
} Arena;


// Funções

Arena * newArena(size_t size);

Arena * ArenaFrom(const void * memory, size_t size);

void * ArenaAlloc(Arena * arena, size_t size_to_alloc);

void ArenaReset(Arena * arena);

void ArenaDestroy(Arena * arena);

void ArenaAutoDestroy(Arena ** arena);
