#include "private.h"
#include "map.h"
#include <string.h>


CJR_Value * CJR_MapGet(CJR_Map * map, char * key) {
    for (size_t i = 0; i < map->length; i++) {
        if (strcmp(map->entries[i].key, key) == 0) {
            return map->entries[i].value;
        }
    }

    return NULL;
}
