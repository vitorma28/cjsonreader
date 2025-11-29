# Explicação de cada componente



## Arena

Struct e conjunto de funções para gerenciar um grande espaço de memória alocada no heap. Assim, evitando realizar diversas alocações no heap e causar desfragmentação na memória.

## Map

Struct e conjunto de funções que simulam um `Map`, tornando possível a leitura e escrita de objetos comparáveis ao JSON.

## JSONReader

Componente principal, contém funções para ler e escrever JSON
