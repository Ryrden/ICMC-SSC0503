#include <stdio.h>

void SelectionSort(int *vetor, int N) {
    int menor_indice;
    int troca = 0;

    for (int i = 0; i < N; i++) {
        menor_indice = i;
        for (int j = i + 1; j < N; j++) {
            if (vetor[j] < vetor[menor_indice])
                menor_indice = j;
        }
        if (i != menor_indice) {
            troca = vetor[menor_indice];
            vetor[menor_indice] = vetor[i];
            vetor[i] = troca;
        }
    }
}