#include "map.h"
#include <stdio.h>


Map * MapSet(Arena * arena, Map * map, char * key, Value * value) {
    printf("Ok2.\n");
    if (map->length == map->maxLength) {
        printf("Ok3.\n");
        void * tmp = ArenaRealloc(
            arena,
            map->entries,
            map->maxLength,
            map->maxLength  * 2
        );
        printf("Ok3.\n");

        if (tmp == NULL) return NULL;
        printf("Ok3.\n");

        map->entries = (MapEntry *) tmp;
        printf("Ok3.\n");

        map->maxLength *= 2;
        printf("Ok3.\n");
    }

    size_t i = map->length;
    printf("Ok2.\n");

    map->entries[i] = newMapEntry(key, value);
    printf("Ok2.\n");

    map->length++;
    printf("Ok2.\n");

    return map;
}
