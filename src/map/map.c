#include "./map.h"

#define MAP_MIN_LENGTH 8


Map * newMap(Arena * arena, size_t maxLength) {
    Map * map = (Map *) ArenaAlloc(arena, sizeof(Map));

    if (map == NULL) return NULL;

    map->maxLength = maxLength == 0 ? MAP_MIN_LENGTH : maxLength;
    
    map->entries = (MapEntry *) ArenaAlloc(arena, sizeof(MapEntry) * map->maxLength);

    if (map->entries == NULL) return NULL;

    map->length = 0;

    return map;
}
