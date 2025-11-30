#include "map.h"


MapEntry * newMapEntry(Arena * arena, char * key, Value * value) {
    MapEntry * mapentry = (MapEntry *) ArenaAlloc(arena, sizeof(MapEntry));

    mapentry->key = key;
    mapentry->value = value;

    return mapentry;
}
