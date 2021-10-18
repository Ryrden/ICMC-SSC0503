#include "metodo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, i;
    scanf("%d", &N);

    int *vetorPrincipal = (int *)malloc(N * sizeof(int));
    int *SubVetorShell = (int *)calloc(sizeof(int), N);
    int *SubVetorQuick = (int *)calloc(sizeof(int), N);

    for (i = 0; i < N; i++) {
        scanf("%d", &vetorPrincipal[i]);
    }

    for (i = 0; i < N; i++) {
        int N2 = i + 1;

        SubVetorShell = (int *)realloc(SubVetorShell, sizeof(int) * N2);
        SubVetorQuick = (int *)realloc(SubVetorQuick, sizeof(int) * N2);

        for (int j = 0; j < N2; j++) {
            int x = vetorPrincipal[j];
            SubVetorShell[j] = x;
            SubVetorQuick[j] = x;
        }

        int Shellcmp = 0;
        int Shellcpy = 0;
        ShellSort(SubVetorShell, N2, &Shellcmp, &Shellcpy);

        int Quickcmp = 0;
        int Quickcpy = 0;
        QuickSort(SubVetorQuick, N2, &Quickcmp, &Quickcpy);

        //printf("\n");
        if ((Shellcmp + Shellcpy) > (Quickcmp + Quickcpy)) {
            printf("Q ");
        } else if ((Quickcmp + Quickcpy) > (Shellcmp + Shellcpy)) {
            printf("S ");
        } else {
            printf("- ");
        }

        //printf("\nSHELL %d - cmp:%d  cpy:%d", i + 1, Shellcmp, Shellcpy);
        //printf("\nQUICK %d - cmp:%d  cpy:%d \n", i + 1, Quickcmp, Quickcpy);
    }
    free(SubVetorShell);
    free(SubVetorQuick);
    free(vetorPrincipal);
    return EXIT_SUCCESS;
}
