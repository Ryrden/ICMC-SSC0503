#include "metodos.h"
#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int metodoEscolhido = escolheMetodo();
    int tamanhoDoVetor;
    int *vetor = criarVetor(&tamanhoDoVetor);
    preencherVetor(vetor, tamanhoDoVetor);

    if (metodoEscolhido == 1) 
        ordenacaoBolha(vetor, tamanhoDoVetor);
    else if (metodoEscolhido == 2)
        ordenacaoSelecao(vetor, tamanhoDoVetor);

    imprimirVetorOrdenado(vetor, tamanhoDoVetor);

    free(vetor);
    return EXIT_SUCCESS;
}
