#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*

Author: Hosana Gomes
Para compilar:
gcc reduce.c -o r

Para executar:
 ./r 100
Onde o primeiro parâmetro é o tamanho do vetor.
*/


long reduce(int *vetor, long tamanho) 
{
    long reduced = 0;
    for (int i = 0; i < tamanho; i++)
    {
        reduced = reduced + vetor[i];
    }    

    return reduced;
}

void popular_vetor(int *vetor, long tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = i + 1;
    }    
}

void imprimir_vetor(int *vetor, long tamanho)
{
    printf("Vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\t", vetor[i]);
        if((i + 1) % 10 == 0) 
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int tamanho = atoi(argv[1]);  // O TAMANHO DA INSTÂNCIA

    int *vetor;
    long reduced;

    vetor = (int *) malloc(sizeof(int) * tamanho);

    popular_vetor(vetor, tamanho);
   // imprimir_vetor(vetor, tamanho);
    reduced = reduce(vetor, tamanho);

    printf("Soma dos valores do vetor: %ld\n", reduced);


    return 0;
}