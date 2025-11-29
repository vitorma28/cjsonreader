#include "./arena.h"
#include <stdlib.h>


void ArenaDestroy(Arena * arena) {
    free(arena->begin);
}
