#include "./arena.h"
#include <stdlib.h>


void __CJR_ArenaAutoDestroy(__CJR_Arena ** arena) {
    __CJR_ArenaDestroy(*arena);

    free(*arena);
    *arena = NULL;
}
