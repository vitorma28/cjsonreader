#include "./map.h"

#define MAP_MIN_LENGTH 8


__CJR_Map * __CJR_newMap(Arena * arena, size_t maxLength) {
    __CJR_Map * map = (__CJR_Map *) ArenaAlloc(arena, sizeof(__CJR_Map));

    if (map == NULL) return NULL;

    map->maxLength = maxLength == 0 ? MAP_MIN_LENGTH : maxLength;
    
    map->entries = (__CJR_MapEntry *) ArenaAlloc(arena, sizeof(__CJR_MapEntry) * map->maxLength);

    if (map->entries == NULL) return NULL;

    map->length = 0;

    return map;
}
