#include <stdio.h>
int buscaOrdenadaSentinela(int vetor[], int n, int item) {
    if (vetor[n - 1] < item) { // se passar disso, com certeza o elemento está no vetor.
        return -1;
    }
    int i = 0;
    while (1) {
        if (vetor[i] >= item) {
            if (vetor[i] == item)
                return i;
            return -1;
        }
        i++;
    }
    return -1; // enfeite pro compilador
}