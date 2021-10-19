#include <stdio.h>

void _heap(int *vetor, int father_index, int last_index);
void _quick(int *vetor, int inicio, int final, int profundidade);

void QuickSort(int *vetor, int N, int profundidade) {
    _quick(vetor, 0, N - 1, profundidade);
}

void _quick(int *vetor, int inicio, int final, int profundidade) {
    int i = inicio;
    int f = final;

    if (profundidade > 15) {
        _heap(vetor, i, f);
        return;
    }
    if (i >= f) {
        return;
    }
    int meio = (i + f) / 2;
    int pivot = vetor[meio];
    int i2 = i;
    int f2 = f;

    while (1) {
        while (vetor[i2] < pivot)
            i2++;
        while (vetor[f2] > pivot)
            f2--;
        if (f2 <= i2)
            break;

        int tmp = vetor[i2];
        vetor[i2] = vetor[f2];
        vetor[f2] = tmp;
        i2++;
        f2--;
    }
    _quick(vetor, i, f2, profundidade + 1);
    _quick(vetor, f2 + 1, f, profundidade + 1);
}

void _heap(int *vetor, int father_index, int last_index) {
    int i = father_index;
    int li = last_index;
    while (i <= li) {
        int son = 2 * i + 1;
        if (son <= li) {
            if (son + 1 <= li && vetor[son + 1] > vetor[son])
                son++;
            if (vetor[i] < vetor[son]) {
                int tmp = vetor[i];
                vetor[i] = vetor[son];
                vetor[son] = tmp;
            } else {
                return;
            }
        }
        i = son;
    }
}