#include "RadixSort.h"
#include <stdio.h>
#include <stdlib.h>

/* Para o método Radix Sort, o programa deve ler um expoente E e o número N de elementos de
um vetor V. Após isso, leia os N elementos de V. Cada elemento é um inteiro sem sinal entre
0 e 2^32. O programa deve imprimir os vetores intermediários em decimal, com a ordenação de cada dígito dada pela base 2^E. */

int main() {
    int E, N;

    scanf("%d", &E);
    scanf("%d", &N);
	
    int vet[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }

    RadixSort(vet, N, E);

    return EXIT_SUCCESS;
}