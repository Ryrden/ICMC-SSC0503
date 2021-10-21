#include <stdio.h>

int BuscaRecursiva(int vetor[], int inicio, int final, int item) {

    if (inicio > final) {
        return -1;
    }
    int meio = (inicio + final) / 2;
    if (vetor[meio] == item) {
        return meio;
    } else if (vetor[meio] < item) {
        return BuscaRecursiva(vetor, meio + 1, final, item);
    } else if (vetor[meio] > item) {
        return BuscaRecursiva(vetor, inicio, meio - 1, item);
    }
}