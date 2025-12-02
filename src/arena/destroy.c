#include "private.h"
#include "./arena.h"
#include <stdlib.h>


void CJR_ArenaDestroy(CJR_Arena * arena) {
    free(arena->begin);
}
