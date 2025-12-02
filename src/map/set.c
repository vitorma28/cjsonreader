#include "private.h"
#include "map.h"
#include <stdio.h>


CJR_Map * CJR_MapSet(CJR_Arena * arena, CJR_Map * map, char * key, CJR_Value * value) {
    if (map->length == map->maxLength) {
        void * tmp = ArenaRealloc(
            arena,
            map->entries,
            map->maxLength,
            map->maxLength  * 2
        );

        if (tmp == NULL) return NULL;

        map->entries = (CJR_MapEntry *) tmp;

        map->maxLength *= 2;
    }

    size_t i = map->length;

    map->entries[i] = CJR_newMapEntry(key, value);

    map->length++;

    return map;
}
