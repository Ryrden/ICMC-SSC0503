#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int *criarVetor(int *tamanhoDoVetor) {
    int tamanho, *vetor;
    if (!scanf("%d", &tamanho))
        exit(EXIT_FAILURE);

    vetor = (int *)malloc(sizeof(int) * tamanho);

    if (tamanho > 0) {
        *tamanhoDoVetor = tamanho;
        return vetor;
    }
    exit(EXIT_FAILURE);
}

void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (!scanf("%d", &vetor[i]))
            exit(EXIT_FAILURE);
}

void imprimirVetorOrdenado(int *vetor, int tamanhoDoVetor) {
    for (int i = 0; i < tamanhoDoVetor; i++)
        printf("%d ", vetor[i]);
}
