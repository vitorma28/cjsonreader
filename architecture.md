# Arquitetura utilizada

## Visão geral

JSONReader utilizará Map para armazenar os valores do JSON.

## Módulos utilizados

- Map -> Serve para representar a estrutura de objetos do javascript;
- JSONReader -> Reader/Writer entre JSON e Map.
- Arena -> Alocador no heap para evitar várias alocações dinâmicas.

## Diagramas de código

Arquivos `readme.md` existem em cada diretório de componente em `src` mostrando o funcionamento de cada arquivo.

A pasta `src` possui um `readme.md` explicando o que cada componente é e para que serve.

### Regras gerais

1. Cada componente de código tem sua própria pasta (exceções deverão ser registradas);
2. Dentro da pasta do componente, tem um arquivo `<componente>.h` conectando todos os arquivos do diretório;
3. O "construtor" da struct (se houver) deve estar em um arquivo `<struct>.c`;
4. As funções referentes a uma struct específica deverão estar em um arquivo no formato `<nome da função>.c` e seus nomes em código deverão estar no formato `<struct><nome da função>` em Pascal Case. Ex.: arquivo `get.c`, função `MapGet`;
