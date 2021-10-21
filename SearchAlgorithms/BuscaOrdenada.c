#include <stdio.h>

int buscaOrdenada(int vetor[], int n, int item) {
    for (int i = 0; i < n; i++)
        if (vetor[i] >= item)
            if (vetor[i] == item)
                return i;
            else
                return -1;
    return -1;
}