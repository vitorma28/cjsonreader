#include <stdio.h>
#include "../../src/arena/arena.h"


int main(void) {
    Arena * arena = newArena(KB(1));

    if (arena == NULL) {
        printf("[ERROR] Falha em newArena.\n");
        return 1;
    }

    Arena * arena2 = ArenaFrom(arena->begin, 64);

    if (arena2 == NULL) {
        printf("[ERROR] Falha em ArenaFrom.\n");
        return 2;
    }

    void * allocated = ArenaAlloc(arena2, 8);

    if (allocated == NULL) {
        printf("[ERROR] Falha em ArenaAlloc.\n");
    }
    else {
        ArenaReset(arena2);

        if (arena2->offset != 0) {
            printf("[ERROR] Falha em ArenaReset.\n");
        }
    }

    ArenaAutoDestroy(&arena);

    if (arena != NULL) {
        printf("[ERROR] Falha em ArenaAutoDestroy.\n");
    }

    printf("Fim do teste de Arena.\n");

    return 0;
}
