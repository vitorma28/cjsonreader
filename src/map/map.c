#include "private.h"
#include "./map.h"

#define MAP_MIN_LENGTH 8


CJR_Map * CJR_newMap(CJR_Arena * arena, size_t maxLength) {
    CJR_Map * map = (CJR_Map *) ArenaAlloc(arena, sizeof(CJR_Map));

    if (map == NULL) return NULL;

    map->maxLength = maxLength == 0 ? MAP_MIN_LENGTH : maxLength;
    
    map->entries = (CJR_MapEntry *) ArenaAlloc(arena, sizeof(CJR_MapEntry) * map->maxLength);

    if (map->entries == NULL) return NULL;

    map->length = 0;

    return map;
}
