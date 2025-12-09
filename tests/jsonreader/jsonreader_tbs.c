#include <stdio.h>
#include "../../src/jsonreader/private.h"


void show(void * value, const void * _) {
    Symbol * sym = (Symbol *) value;
    
    printf("%d %c\n", sym->type, sym->value == NULL ? 'N' : 'V');
}


int main(void) {
    char * text = "{\"teste\": 10, \"chave\": \"valor\"}";

    CJR_Arena * arena = CJR_newArena(MB(1));

    if (arena == NULL) {
        printf("[ERROR] Arena não foi carregada.");
        return 1;
    }

    Vector * symbols = tokenizingBySymbols(arena, text);

    if (symbols == NULL) {
        printf("[ERROR] Falha ao criar o vetor de símbolos.");
        return 2;
    }

    // VectorForEach(symbols, show);

    puts("\n");

    for (size_t i = 0; i < VectorLength(symbols); i++) {
        Symbol * sym = (Symbol *) VectorGet(symbols, i);

        printf("Type: %d, hasValue: %s\n", sym->type, sym->value == NULL ? "false" : "true");
    }
    
    return 0;
}
