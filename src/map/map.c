#include "./map.h"

#define MAP_MIN_LENGTH 8


Map * newMap(Arena * arena) {
    Map * map = (Map *) ArenaAlloc(arena, sizeof(Map));

    if (map == NULL) return NULL;

    map->length = 0;
    map->maxLength = MAP_MIN_LENGTH;
    map->entries = (MapEntry *) ArenaAlloc(arena, sizeof(MapEntry) * MAP_MIN_LENGTH);

    return map;
}
