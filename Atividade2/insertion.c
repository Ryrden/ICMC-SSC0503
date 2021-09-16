#include <stdio.h>

void insertionSort(int *vetor, int N, int *trocas, int *comparacao) {
    for (int i = 1; i < N; i++) {
        int x = vetor[i];
        (*trocas)++;
        int j = i - 1;
        if (j >= 0)
            (*comparacao) += 1;
        while (j >= 0 && vetor[j] > x) {
            vetor[j + 1] = vetor[j];
            (*trocas)++;
            j--;
            if (j >= 0)
                (*comparacao)++;
        }
        vetor[j + 1] = x;
        (*trocas)++;
    }
}