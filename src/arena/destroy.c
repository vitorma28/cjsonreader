#include "./arena.h"
#include <stdlib.h>


void __CJR_ArenaDestroy(__CJR_Arena * arena) {
    free(arena->begin);
}
