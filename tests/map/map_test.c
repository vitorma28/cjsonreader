#include <stdio.h>
#include "../../src/map/map.h"


int main(void) {
    Arena * arena = newArena(KB(1));

    if (arena == NULL) {
        printf("[ERROR] Falha ao criar a Arena.\n");
        return 1;
    }


    Map * map = newMap(arena, 32);

    if (map == NULL) {
        printf("[ERROR] Falha ao criar o Map.\n");
        return 2;
    }


    Value * value = newValue(arena, STRING, "teste de valor");

    if (value == NULL) {
        printf("[ERROR] Falha ao criar um valor.\n");
        return 3;
    }

    void * tmp = MapSet(arena, map, "chave-teste", value);

    if (tmp == NULL) {
        printf("[ERROR] Erro na definição no Map.\n");
    }


    Value * result = MapGet(map, "chave-teste");

    if (result == NULL) {
        printf("[ERROR] MapGet retornou NULL.\n");
        return 4;
    }

    if (!(result->type == value->type && result->value == value->value)) {
        printf("[ERROR] Valor obtido diferente de valor definido.\n");
    }
    

    ArenaAutoDestroy(&arena);

    return 0;
}
