#include "CountingSort.h"
#include <stdio.h>
#include <stdlib.h>

/* Para o método Counting Sort, o programa deve ler o número K de chaves distintas do vetor V e
o número N de elementos de V. Após isso, leia os N elementos de V. Cada elemento terá valor
entre 0 e K - 1. O programa deve imprimir a posição que cada elemento vai ocupando no vetor ordenado. */

void CountingSort(int *a, int n, int k) {
    int *count = CriarVetor(k);
    int *aux = CriarVetor(k);
    int *aux2 = CriarVetor(n);
    for (int i = 0; i < n; i++) {
        count[a[i]] += 1;
    }
    for (int i = 0; i < n; i++) {
        int pos = 0;
        int j = 0;
        while (j < a[i]) {
            pos += count[j];
            j++;
        }
        pos += aux[a[i]];
        aux2[pos] = a[i];
        aux[a[i]]++;
        printf("%d %d\n", a[i], pos);
    }
    for (int i = 0; i < n; i++) 
        a[i] = aux2[i];
    
    LiberarVetor(&count);
    LiberarVetor(&aux);
    LiberarVetor(&aux2);
}

void LiberarVetor(int **a) {
    free(*a);
}

int *CriarVetor(int b) {
    int *a = malloc(sizeof(int) * b);
    if (a == NULL)
        exit(EXIT_FAILURE);

    ZerarVetor(a, b);
    return a;
}

void ZerarVetor(int *a, int b) {
    for (int i = 0; i < b; i++) 
        a[i] = 0;
}