#include <stdio.h>

int buscaSimples(int vetor[], int n, int item) {
    for (int i = 0; i < n; i++)
        if (vetor[i] == item)
            return i;
    return -1;
}