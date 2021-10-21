#include <stdio.h>

int BuscaBinaria(int vetor[], int n, int item) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == item) {
            return meio;
        } else if (vetor[meio] < item) {
            inicio = meio + 1;
        } else if (vetor[meio] > item) {
            fim = meio - 1;
        }
    }
    return -1;
}