#include "map.h"
#include <string.h>


Value * MapGet(Map * map, char * key) {
    for (size_t i = 0; i < map->length; i++) {
        if (strcmp(map->entries[i].key, key) == 0) {
            return map->entries[i].value;
        }
    }

    return NULL;
}
