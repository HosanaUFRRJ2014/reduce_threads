#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define COUNTING_SORT 1
#define SELECTION_SORT 2
#define HEAP_SORT 3
#define RADIX_SORT 4

/*implementação dos algoritmos counting sort, heap sort  selection sort e radix*/

/*inline*/ double countingSort(int *vetor, int tamanho)
{
    int i, j, tam_freq, contador = 0;
	int *frequencia = NULL;
	frequencia = (int *) malloc(sizeof(int) * tamanho *5);
	tam_freq = sizeof(frequencia)/sizeof(frequencia[0]); //colocar em define
    //zerar o vetor frequencia
	for (i = 0; i < tam_freq; i++) {
	    frequencia[i] = 0;
	}
printf("%d\n", tamanho);
   //inicio contagem de tempo
	double comeco = (double) clock () / CLOCKS_PER_SEC;
	//printf("vetor[0]: %d\n", vetor[0]);

	for (i = 0; i < tam_freq; i++)
	{	//printf("%d\t", vetor[i]);
		frequencia[vetor[i]]++; //só funciona para vetores que tem o maximo valor sendo (tamanho - 1)
	}

    i = 0;
    while(i < tam_freq)
    {
    	//int aux = i;
    	contador = frequencia[i];
    	while(contador > 0)
    	{
    		vetor[j] = i;
    		j++;

    		contador--;
    	}

    	i++;
    }

    //fim contagem de tempo
    double fim = (double) clock () / CLOCKS_PER_SEC;

    return (fim - comeco); //retornar o tempo percorrido



}

int main(int argc, char const *argv[])
{
	int opcao = atoi(argv[1]);         //o tipo de algoritmo
	int tamanho = atoi(argv[2]);       //o TAMANHO DA INSTÂNCIA
	double tempo = 0;   //armazena o tempo de execuçaõ do algoritmo escolhido

	int i;

	int *vetor = NULL;
	vetor = (int *) malloc(tamanho * sizeof(int));

	//preencher vetor
	srand(time(NULL));

	//int aux_tamanho = tamanho;
	for (i = 0; i < tamanho; i++)
	{
		vetor[i] = (int) rand() % (tamanho * 5);
                //vetor[i] = aux_tamanho;
                //aux_tamanho--;
		//printf("%d	", vetor[i]);
	}
	printf("\n");

	//determinação de qual algoritmo será aplicado
	switch(opcao)
	{
		case COUNTING_SORT :
		   printf("Ordenacao pelo COUNTING_SORT...");
                   tempo = countingSort(vetor, tamanho);

		break;

		default:
                   printf("Opcao invalida!!\n");
	}



	//imprimir vetor ordenado
	/*printf("Vetor ordenado:\n");
	for (i = 1; i <= tamanho; i++)
	{
		printf("%-5d", vetor[i - 1]);

		if(i % 10 == 0 )   //quebra de linha
			printf("\n");
	}*/

	printf("\n\nTamanho do vetor: %d\n",tamanho);

	printf("\nTempo de execucao: %f\n", tempo);

	

	return 0;
}
