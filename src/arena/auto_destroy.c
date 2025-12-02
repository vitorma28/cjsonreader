#include "private.h"
#include "./arena.h"
#include <stdlib.h>


void CJR_ArenaAutoDestroy(CJR_Arena ** arena) {
    CJR_ArenaDestroy(*arena);

    free(*arena);
    *arena = NULL;
}
