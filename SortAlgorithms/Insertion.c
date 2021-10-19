#include <stdio.h>

void insertionSort(int *vetor, int N) {
    for (int i = 1; i < N; i++) {
        int x = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > x) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = x;
    }
}