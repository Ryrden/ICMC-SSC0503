#include <stdio.h>

int BuscaPorInterpolacao(int vetor[], int n, int item) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        // Garantindo que os elementos não são iguais
        if (vetor[fim] == vetor[inicio]) {
            if (vetor[inicio] == item)
                return inicio;
            else
                return -1;
        }
        int meio = inicio + (item - vetor[inicio]) * (fim - inicio) / (vetor[fim] - vetor[inicio]);
        if (vetor[meio] == item) {
            return meio;
        } else if (vetor[meio] < item) {
            inicio = meio + 1;
        } else if (vetor[meio] > item) {
            fim = meio - 1;
        }
    }
    return -1;
}