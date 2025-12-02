#include "private.h"
#include "map.h"


CJR_Value * CJR_newValue(CJR_Arena * arena, CJR_JSTypes dataType, void * dataValue) {
    CJR_Value * value = (CJR_Value *) ArenaAlloc(arena, sizeof(CJR_Value));

    if (value == NULL) return NULL;

    value->type = dataType;
    value->value = dataValue;

    return value;
}
