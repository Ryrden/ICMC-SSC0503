#ifndef METODO_H
#define METODO_H

void ShellSort(int *vet, int t, int *cmp, int *cpy) ;

void QuickSort(int *vetor, int N, /*int profundidade,*/ int *cmp, int *cpy);
void _quick(int *vetor, int inicio, int final, /*int profundidade,*/ int *cmp, int *cpy);
void _heap(int *vetor, int father_index, int last_index);
#endif