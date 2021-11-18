#include "RadixSort.h"
#include <stdio.h>
#include <stdlib.h>

/* Para o método Radix Sort, o programa deve ler um expoente E e o número N de elementos de
um vetor V. Após isso, leia os N elementos de V. Cada elemento é um inteiro sem sinal entre
0 e 2^32. O programa deve imprimir os vetores intermediários em decimal, com a ordenação de
cada dígito dada pela base 2^E. */

void RadixSort(int *a, int n, int e) {
    int max = a[0];
    int digmax = 0;
    int base = 2 << (e - 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int l = 1;
    while (l <= max) {
        l *= base;
        digmax++;
    }
    int *count = CriarVetor(base);
    int *aux2 = CriarVetor(n);
    int digit;
    for (int i = 0; i < digmax; i++) {
        for (int j = 0; j < n; j++) {
            digit = GetRadixDigit(a[j], e, i);
            count[digit] += 1;
        }
        for (int j = 1; j < base; j++) {
            count[j] += count[j - 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            digit = GetRadixDigit(a[j], e, i);
            aux2[count[digit] - 1] = a[j];
            count[digit]--;
        }
        for (int j = 0; j < n; j++) {
            a[j] = aux2[j];
        }
        PrintVetor(a, n);
        ZerarVetor(count, base);
        ZerarVetor(aux2, n);
    }
    LiberarVetor(&count);
    LiberarVetor(&aux2);
}

void PrintVetor(int *a, int b) {
    for (int i = 0; i < b; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int GetRadixDigit(int num, int exp, int it) {
    return (num >> (it * exp)) & ((1 << exp) - 1);
}

void LiberarVetor(int **a) {
    free(*a);
}

int *CriarVetor(int b) {
    int *a = malloc(sizeof(int) * b);
    if (a == NULL)
        exit(EXIT_FAILURE);

    ZerarVetor(a, b);
    return a;
}

void ZerarVetor(int *a, int b) {
    for (int i = 0; i < b; i++) {
        a[i] = 0;
    }
    return;
}