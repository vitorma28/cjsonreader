#include "./arena.h"


void * ArenaAlloc(Arena * arena, size_t size_to_alloc) {
    // Se o tamanho a ser alocado for maior que o disponível
    if (arena->offset + size_to_alloc > arena->size) {
        return NULL;
    }

    void * ptr = arena->begin + arena->offset;
    arena->offset += size_to_alloc;

    return ptr;
}
