#include "map.h"
#include <stdio.h>


Map * MapSet(Arena * arena, Map * map, char * key, Value * value) {
    if (map->length == map->maxLength) {
        void * tmp = ArenaRealloc(
            arena,
            map->entries,
            map->maxLength,
            map->maxLength  * 2
        );

        if (tmp == NULL) return NULL;

        map->entries = (MapEntry *) tmp;

        map->maxLength *= 2;
    }

    size_t i = map->length;

    map->entries[i] = newMapEntry(key, value);

    map->length++;

    return map;
}
