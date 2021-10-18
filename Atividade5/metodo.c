#include <stdio.h>

void _quick(int *vetor, int inicio, int final, int *cmp, int *cpy) {
    int i = inicio;
    int f = final;

    if (i >= f) {
        return;
    }
    int meio = (i + f) / 2;
    int pivot = vetor[meio];
    *cpy += 1;
    int i2 = i;
    int f2 = f;

    while (1) {

        while ((*cmp)++, vetor[i2] < pivot) {
            i2++;
        }

        while ((*cmp)++, vetor[f2] > pivot) {
            f2--;
        }

        if (f2 <= i2) {
            break;
        }

        *cpy += 3;
        int tmp = vetor[i2];
        vetor[i2] = vetor[f2];
        vetor[f2] = tmp;
        i2++;
        f2--;
    }
    _quick(vetor, i, f2, cmp, cpy);
    _quick(vetor, f2 + 1, f, cmp, cpy);
}

void QuickSort(int *vetor, int N, int *cmp, int *cpy) {
    _quick(vetor, 0, N - 1, cmp, cpy);
}

void ShellSort(int *vet, int t, int *cmp, int *cpy) {
    int gap = 1;
    while (gap < t) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while (gap > 0) {
        for (int i = gap; i < t; i++) {
            int x = vet[i];
            *cpy += 1;
            int j = i - gap;

            while (j >= 0 && ((*cmp)++, vet[j] > x)) {
                vet[j + gap] = vet[j];
                *cpy += 1;
                j -= gap;
            }
            *cpy += 1;
            vet[j + gap] = x;
        }
        gap /= 2;
    }
}
