#include "private.h"
#include "map.h"
#include <string.h>
#include <sys/types.h>


static ssize_t MapIndexOfKey(CJR_Map * map, char * key) {
    for (size_t i = 0; i < map->length; i++) {
        if (!strcmp(key, map->entries[i].key)) {
            return i;
        }
    }
    
    return -1;
}


CJR_Map * CJR_MapSet(CJR_Arena * arena, CJR_Map * map, char * key, CJR_Value * value) {
    ssize_t index = MapIndexOfKey(map, key);

    if (index != -1) {
        map->entries[index].value = value;

        return map;
    }


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



CJR_Value * CJR_MapGet(CJR_Map * map, char * key) {
    ssize_t index = MapIndexOfKey(map, key);

    if (index == -1) return NULL;

    return &map->entries[index];
}


CJR_Map * CJR_MapRemove(CJR_Map * map, char * key) {
    ssize_t index = MapIndexOfKey(map, key);

    if (index == -1) return NULL;

    map->entries[index] = map->entries[map->length - 1];

    map->length--;

    return map;
}
