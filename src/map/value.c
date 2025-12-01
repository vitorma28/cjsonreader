#include "map.h"


__CJR_Value * __CJR_newValue(Arena * arena, __CJR_JSTypes dataType, void * dataValue) {
    __CJR_Value * value = (__CJR_Value *) ArenaAlloc(arena, sizeof(__CJR_Value));

    if (value == NULL) return NULL;

    value->type = dataType;
    value->value = dataValue;

    return value;
}
