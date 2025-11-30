#include "./arena.h"
#include <stdlib.h>


void ArenaAutoDestroy(Arena ** arena) {
    ArenaDestroy(*arena);

    free(*arena);
    *arena = NULL;
}
