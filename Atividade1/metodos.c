#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int escolheMetodo() {
    char inserirMetodo[8];
    setbuf(stdin, 0);
    if (!(fgets(inserirMetodo, 8, stdin)))
        exit(1);
    inserirMetodo[strcspn(inserirMetodo, "\n")] = 0;
    if (strcmp(inserirMetodo, "selecao") == 0) {
        return 2;
    } else if (strcmp(inserirMetodo, "bolha") == 0) {
        return 1;
    }
    exit(EXIT_FAILURE);
}

void ordenacaoSelecao(int *vetor, int tamanhoDoVetor) {
    int menor_indice;
    int troca = 0;

    for (int i = 0; i < tamanhoDoVetor; i++) {
        menor_indice = i;
        for (int j = i + 1; j < tamanhoDoVetor; j++) {
            //Comparando dois vetores
            printf("C %d %d \n", menor_indice, j);
            if (vetor[j] < vetor[menor_indice]) {
                menor_indice = j;
            }
        }
        //Trocando Menor valor encontrado com a posição fixada
        if (i != menor_indice) {
            printf("T %d %d \n", i, menor_indice);
            troca = vetor[menor_indice];
            vetor[menor_indice] = vetor[i];
            vetor[i] = troca;
        }
    }
}

void ordenacaoBolha(int *vetor, int tamanhoDoVetor) {
    int troca, flag_trocas, semTrocas;
    int tamVet2 = tamanhoDoVetor - 1;
    for (int i = 0; i < tamanhoDoVetor; i++) {
        flag_trocas = semTrocas = 0;
        for (int j = 0; j < tamVet2; j++) {
            printf("C %d %d\n", j, j + 1);
            if (vetor[j] > vetor[j + 1]) {
                printf("T %d %d\n", j, j + 1);
                troca = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = troca;
                flag_trocas = 1;
                semTrocas = 0;
            } else
                semTrocas++;
        }
        tamVet2 -= semTrocas + 1;
        if (flag_trocas == 0)
            return;
    }
}
