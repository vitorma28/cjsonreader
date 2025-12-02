#include "private.h"
#include "map.h"


CJR_MapEntry CJR_newMapEntry(char * key, CJR_Value * value) {
    CJR_MapEntry mapentry;

    mapentry.key = key;
    mapentry.value = value;

    return mapentry;
}
