#include "insertion.h"
#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, troca = 0, comparacao = 0;
    int *tam;
    int **vetor1, **vetor2;

    scanf("%i", &N); //Quantos Vetores serão registrados

    tam = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%i", &tam[i]); //O tamanho de cada vetor

    vetor1 = (int **)malloc(sizeof(int *) * N); //Para o InsertionSort
    vetor2 = (int **)malloc(sizeof(int *) * N); ////Para o MergeSort

    for (int i = 0; i < N; i++) {
        vetor1[i] = (int *)malloc(sizeof(int) * tam[i]);
        vetor2[i] = (int *)malloc(sizeof(int) * tam[i]);
        for (int j = 0; j < tam[i]; j++) {
            scanf("%i", &vetor1[i][j]);
            vetor2[i][j] = vetor1[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        insertionSort(vetor1[i], tam[i], &troca, &comparacao);
        printf("I %i %i %i\n", tam[i], troca, comparacao);

        troca = 0;
        comparacao = 0;

        mergeSort(vetor2[i], 0, tam[i] - 1, &troca, &comparacao);

        printf("M %i %i %i\n", tam[i], troca, comparacao);

        troca = 0;
        comparacao = 0;
    }

    free(tam);

    for (int i = 0; i < N; i++) {
        free(vetor1[i]);
        free(vetor2[i]);
    }

    free(vetor1);
    free(vetor2);

    return EXIT_SUCCESS;
}