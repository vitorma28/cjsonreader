#include "map.h"


MapEntry newMapEntry(char * key, Value * value) {
    MapEntry mapentry;

    mapentry.key = key;
    mapentry.value = value;

    return mapentry;
}
