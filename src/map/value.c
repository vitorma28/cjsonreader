#include "map.h"


Value * newValue(Arena * arena, JSTypes dataType, void * dataValue) {
    Value * value = (Value *) ArenaAlloc(arena, sizeof(Value));

    value->type = dataType;
    value->value = dataValue;

    return value;
}
