#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<pthread.h>
#include<unistd.h>
#include <sys/syscall.h>

/*

Author: Hosana Gomes
Para compilar:
gcc reduce_threads.c -lpthread -o rt

Para executar:
 ./rt 100 10
Onde o primeiro parâmetro é o tamanho do vetor e 
o segundo parâmetro é o número de threads.
*/



pthread_mutex_t mux;
pthread_mutex_t cria;

int num_variaveis_por_thread;
long reduced;
long ultimo_index;
long limitador;

void * reduce(void *argumento) 
{
    int * vetor;
    vetor = (int *) argumento;
    long soma = 0;
    pthread_mutex_unlock(&cria);

//    pthread_mutex_lock(&mux);
        ultimo_index = limitador;
        limitador = ultimo_index + num_variaveis_por_thread;
        //fflush(stdout);
  //  pthread_mutex_unlock(&mux);

    for (int i = ultimo_index; i < limitador; i++)
    {
        soma = soma + vetor[i];
    }

    pthread_mutex_lock(&mux);
        reduced = reduced + soma;       
        //fflush(stdout);
    pthread_mutex_unlock(&mux);    

//    return reduced;
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
    int num_threads = atoi(argv[2]);  // Número de Threads
    //int opcao_paralelizacao = atoi(argv[2]);  // Se é processo ou thread
    //int num_proc_thread = atoi(argv[3]);  // Quantidade processos ou threads

    int *vetor;

    if(num_threads > tamanho) {
        printf("Erro: num_threads precisa ser maior que tamanho do vetor\n");
        exit(0);
    }

    //Tratamento de só aceitar (tam_vetor % num_threads == 0)
    if (tamanho % num_threads != 0)
    {
        printf("Erro:Tamanho do vetor precisa ser divisível pelo num_threads\n");
        exit(0);
    }

    reduced = 0;
    num_variaveis_por_thread = tamanho/num_threads;
    ultimo_index = 0;
    limitador = 0;

    pthread_t id[num_threads];
    vetor = (int *) malloc(sizeof(int) * tamanho);

    popular_vetor(vetor, tamanho);

    pthread_mutex_init(&mux, NULL);
    pthread_mutex_init(&cria, NULL);

    for (int i = 0; i < num_threads; i++){
        pthread_mutex_lock(&cria);
        pthread_create(&id[i], NULL, reduce, (void *) vetor); //pode faltar &
    
    }   
    for(int i = 0; i < num_threads; i++)
        pthread_join(id[i], NULL);

  //  imprimir_vetor(vetor, tamanho);
  
    printf("Soma dos valores do vetor: %ld\n", reduced);


    return 0;
}