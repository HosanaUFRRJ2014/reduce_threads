# reduce_threads
Uma implementação de uma função de reduce em C usando threads para o cumprimento do primeiro trabalho da disciplina de TEPC.


## Breve introdução

- O arquivo `reduce.c` contém uma implementação de reduce sem threads, isto é, um *código sequencial*.
- O arquivo `reduce_threads.c` contém uma implementação de reduce com threads, isto é, um *código paralelo*.

## Como foi feita a parelização
A parelização ou modernização de código consistiu em colocar dado número de threads para computar uma quantidade igual de elementos do vetor. Para isso, o usuário da aplicação precisa fornecer o tamanho do vetor que será gerado automaticamente pelo programa e o número de threads que deseja. Para fins didáticos, a geração do vetor é uma simples atribuição de valor do índice do elemento + 1. 

**Importante:** o tamanho do vetor precisa ser múltiplo do número de threads.

## Para compilar:
### Código sequencial
    gcc reduce.c -o reduce
    
### Código paralelo
    gcc reduce_threads.c -lpthread -o reduce_threads
    

## Para executar:
### Código sequencial
    ./reduce <tamanho_vetor>
    
### Código paralelo
    ./reduce_threads <tamanho_vetor> <num_threads>
