#include <stdio.h>

void ShellSort(int *vetor, int N) {
    int gap = 1;
    //Determinando Gap
    while (gap < N) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while (gap > 0) {
        for (int i = gap; i < N; i++) {
            // fixado
            int x = vetor[i];
            // fixado anteriormente
            int j = i - gap;
            while (j >= 0 && vetor[j] > x) {
                vetor[j + gap] = vetor[j]; // swap
                j -= gap;
            }
            vetor[j + gap] = x;
        }
        gap /= 2;
    }
}
