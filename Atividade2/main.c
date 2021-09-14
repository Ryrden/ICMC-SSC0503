#include "insertion.h"
#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, troca = 0, comparacao = 0;
    int *tam;
    int **vetor, **banco;

    scanf("%i", &N); //Quantos Vetores serão registrados

    tam = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%i", &tam[i]); //O tamanho de cada vetor
    }

    vetor = (int **)malloc(sizeof(int *) * N);

    for (int i = 0; i < N; i++) {
        vetor[i] = (int *)malloc(sizeof(int) * tam[i]);
        for (int j = 0; j < tam[i]; j++) {
            scanf("%i", &vetor[i][j]);
        }
    }

    banco = vetor;

    for (int i = 0; i < N; i++) {

        insertionSort(vetor[i], tam[i], &troca, &comparacao);
        printf("I %i %i %i\n", tam[i], troca, comparacao);

        vetor = banco;
        troca = 0;
        comparacao = 0;

        mergeSort(vetor[i], 0, tam[i] - 1, &troca, &comparacao);

        printf("M %i %i %i\n", tam[i], troca, comparacao);

        troca = 0;
        comparacao = 0;
    }

    free(tam);

    for (int i = 0; i < N; i++) {
        free(vetor[i]);
    }

    free(vetor);

    return EXIT_SUCCESS;
}

;