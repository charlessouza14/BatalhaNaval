# Batalha Naval com Habilidades Especiais

Meu projeto de Batalha Naval para a faculdade! Neste programa, criei um tabuleiro 10x10 com navios e habilidades especiais que têm diferentes áreas de efeito.

## O que o programa faz

O programa cria um tabuleiro de Batalha Naval e mostra como três tipos de habilidades especiais afetam diferentes áreas:

1. **Cone** - Uma área em forma de triângulo que se expande de cima para baixo
2. **Cruz** - Uma área em formato de cruz (como um "+")*
3. **Octaedro** - Uma área em formato de losango

## Como funciona

- O tabuleiro usa números para representar diferentes coisas:
  - 0 = Água (aparece como ~)
  - 3 = Navio (aparece como N)
  - 5 = Área afetada pela habilidade (aparece como X)

- Para cada habilidade, o programa:
  1. Cria uma matriz 5x5 que representa o formato da habilidade
  2. Define onde a habilidade será usada no tabuleiro
  3. Mostra o tabuleiro com a área afetada pela habilidade

## Como executar

1. Salve o código em um arquivo chamado `batalhaNaval.c`
2. Abra o terminal ou prompt de comando
3. Navegue até a pasta onde salvou o arquivo
4. Compile o programa:
```
   gcc -o batalhaNaval batalhaNaval.c
```
5. Execute o programa:
```
   ./batalhaNaval
```
   (No Windows, use `batalhaNaval.exe`)

## O que aprendi

- Como usar matrizes para representar um tabuleiro 2D
- Como criar diferentes formatos usando condições dentro de loops
- Como sobrepor uma matriz menor (habilidade) em uma matriz maior (tabuleiro)
- Como mostrar informações no formato de um tabuleiro de jogo

Este projeto foi divertido porque pude ver como podemos usar matrizes para criar efeitos visuais interessantes no jogo!
