# Structs

## Map

Struct principal

Simula a estrutura do JSON. É uma lista de MapEntry.

## MapEntry

É um par de uma chave string com um valor Value.

## Value

Representa um valor em JSON, que armazena o seu tipo (um enum) e um `void *` para o seu valor.


# Enums

## JSTypes

Representa todos os tipos presentes em um JSON: `String`, `Number`, `Boolean`, `Null`, `Array`, `Object`.


# Funções

- newMap: Monta um novo Map.
- MapGet: Obtém um valor de um Map com base em sua chave.
- MapSet: Define uma chave e valor a um Map.

- newValue:
