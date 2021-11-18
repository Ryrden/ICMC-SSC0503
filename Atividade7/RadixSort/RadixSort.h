#ifndef RADIXSORT_H
#define RADIXSORT_H

void RadixSort(int *a, int n, int e);
int GetRadixDigit(int num, int exp, int it);
int *CriarVetor(int b);
void PrintVetor(int *a, int b);
void LiberarVetor(int **a);
void ZerarVetor(int *a, int b);

#endif // RADIXSORT_H