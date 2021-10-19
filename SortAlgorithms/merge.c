#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int media, int fim) {

    int *bancoVetor = (int *)malloc(sizeof(int) * (fim - inicio + 1));
    int i = inicio, j = media + 1, k = 0;

    while (i <= media && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            bancoVetor[k] = vetor[i];
            k++;
            i++;
        } else {
            bancoVetor[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i <= media) {
        bancoVetor[k] = vetor[i];
        k++;
        i++;
    }
    
    while (j <= fim) {
        bancoVetor[k] = vetor[j];
        k++;
        j++;
    }

    for (int i = inicio; i <= fim; i++) {
        vetor[i] = bancoVetor[i - inicio];
    }

    free(bancoVetor);
}

void mergeSort(int *vetor, int inicio, int fim) {
    int media;

    if (fim > inicio) {
        media = (fim + inicio) / 2;
        mergeSort(vetor, inicio, media);
        mergeSort(vetor, media + 1, fim);
        merge(vetor, inicio, media, fim);
    }
}