#include <stdio.h>
#include <stdlib.h>
#include "CountingSort.h"

/* Para o método Counting Sort, o programa deve ler o número K de chaves distintas do vetor V e
o número N de elementos de V. Após isso, leia os N elementos de V. Cada elemento terá valor
entre 0 e K - 1. O programa deve imprimir a posição que cada elemento vai ocupando no vetor ordenado. */

int main() {

	int K;
	int N;
	int *vet;

	scanf("%d", &K);
	scanf("%d", &N);

	vet = (int*) malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++){
		scanf("%d", &vet[i]);
	}

	CountingSort(vet, N, K);

	free(vet);

    return EXIT_SUCCESS;
}