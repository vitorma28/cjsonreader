# Structs

Struct principal: Arena

Contém o início e fim do bloco de memória, tamanho e posição atual do ponteiro do heap.

# Funções

- newArena: Constrói uma struct Arena nova com heap novo.
- ArenaFrom: Constrói uma struct Arena a partir de um heap já alocado.
- ArenaAlloc: Aloca um espaço na memória da Arena.
- ArenaReset: Desaloca tudo na Arena.
- ArenaDestroy: Faz um free de toda a arena. Apenas da memória, não da struct.
- ArenaAutoDestroy: O mesmo que ArenaDestroy. Porém, também desaloca o struct.
