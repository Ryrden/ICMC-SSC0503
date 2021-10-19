#include <stdio.h>

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
void heapSort(int *vetor, int N) {
    // Fase 1 - quando não se tem uma heap
    for (int i = N / 2; i >= 0; i--)
        _heap(vetor, i, N - 1);
    // Fase 2 - quando se tem uma heap
    for (int i = N - 1; i > 0; i--) {
        int tmp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = tmp;
        _heap(vetor, 0, i - 1);
    }
}
