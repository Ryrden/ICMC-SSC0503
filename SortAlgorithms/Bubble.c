#include <stdio.h>

void BubbleSort(int *vetor, int N) {
    int troca = 0;
    int sorted, semTrocas;
    int N2 = N - 1;
    for (int i = 0; i < N; i++) {
        sorted = 0;
        semTrocas = 0;
        for (int j = 0; j < N2; j++) {
            if (vetor[j] > vetor[j + 1]) {
                troca = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = troca;
                sorted = 1;
                semTrocas = 0;
            } else
                semTrocas++;
        }
        N2 -= semTrocas + 1;
        if (sorted == 0)
            return;
    }
}