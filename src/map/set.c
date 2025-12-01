#include "map.h"
#include <stdio.h>


__CJR_Map * __CJR_MapSet(Arena * arena, __CJR_Map * map, char * key, __CJR_Value * value) {
    if (map->length == map->maxLength) {
        void * tmp = ArenaRealloc(
            arena,
            map->entries,
            map->maxLength,
            map->maxLength  * 2
        );

        if (tmp == NULL) return NULL;

        map->entries = (__CJR_MapEntry *) tmp;

        map->maxLength *= 2;
    }

    size_t i = map->length;

    map->entries[i] = __CJR_newMapEntry(key, value);

    map->length++;

    return map;
}
