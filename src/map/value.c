#include "map.h"


Value * newValue(Arena * arena, JSTypes dataType, void * dataValue) {
    Value * value = (Value *) ArenaAlloc(arena, sizeof(Value));

    if (value == NULL) return NULL;

    value->type = dataType;
    value->value = dataValue;

    return value;
}
