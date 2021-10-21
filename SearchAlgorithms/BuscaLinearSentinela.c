#include <stdio.h>

int buscaSimplesSentinela(int vetor[], int n, int item) {
    int i = 0;
    vetor[n] = item;
    while (1) {
        if (vetor[i] == item)
            break;
        i++;
    }
    if (i < n)
        return i;
    return -1;
}