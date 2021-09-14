#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int media, int fim, int *troca, int *comparacao) {

    int *bancoVetor = (int *)malloc(sizeof(int) * (fim - inicio + 1));

    int i = inicio, j = media + 1, k = 0;

    while (i <= media && j <= fim) {
        *comparacao += 1;
        *troca += 1;
        if (vetor[i] <= vetor[j]) {
            bancoVetor[k] = vetor[i];
            k++;
            i++;
        } else {
            bancoVetor[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i <= media) {
        *troca += 1;

        bancoVetor[k] = vetor[i];
        k++;
        i++;
    }

    while (j <= fim) {
        *troca += 1;

        bancoVetor[k] = vetor[j];
        k++;
        j++;
    }

    for (int i = inicio; i <= fim; i++) {
        *troca += 1;
        vetor[i] = bancoVetor[i - inicio];
    }

    free(bancoVetor);
}

void mergeSort(int *vetor, int inicio, int fim, int *troca, int *comparacao) {
    int media;

    if (fim > inicio) {
        media = (fim + inicio) / 2;
        mergeSort(vetor, inicio, media, troca, comparacao);
        mergeSort(vetor, media + 1, fim, troca, comparacao);
        merge(vetor, inicio, media, fim, troca, comparacao);
    }
}

/*
void _merge2Vs(int a[], int c1, int f1, int c2, int f2, int b[])
    int i1 = c1; //começo da lista 1
    int i2 = c2; //começo da lista 2
    int j = 0;
    while(i1 <= f1 && i2 <= f2){
        if (a[i1] <= a[i2]){
            b[j] = a[i1];
            j++;
            i1++;
        } else {
            b[j] = a[i2];
            j++;
            i2++;
        }
    }
    while (i1 <= f1) {
        b[j] = a[i1];
        j++
        i1++;
    }
    while (i2 <= f2) {
        b[j] = a[i2];
        j++
        i2++;
    }
    j = 0;
    for(int i = c1; i <= f2; i++, j++){
        a[i] = b[j];
    }
}
void _merge(int a[], int c, int f, int b[]){
    // caso base
    if (c >= f){
        return;
    }
    int meio = (c+f) / 2;
    _merge(a, c, meio, b); //ordenar do começo até o meio
    _merge(a, meio + 1, f, b); //ordenar após o meio até o final
    _merge2Vs(a, c, meio, meio+1, f, b); //Une 2 vetores ordenados 
}
void mergeSort(int a[], int n){
    int *b = malloc(sizeof(int) * n);
    if (b == NULL){
        printf("NAO DEU\n");
        exit(-1);    
    }
    _merge(a, 0, n - 1, b);
    free(b);
}
*/