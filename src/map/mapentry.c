#include "map.h"


__CJR_MapEntry __CJR_newMapEntry(char * key, __CJR_Value * value) {
    __CJR_MapEntry mapentry;

    mapentry.key = key;
    mapentry.value = value;

    return mapentry;
}
