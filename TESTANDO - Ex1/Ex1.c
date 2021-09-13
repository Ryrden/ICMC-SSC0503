#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
    if (num1 > num2)
        return num1;
    return num2;
}

int main() {
    //ENTRADA
    int numero1, numero2;
    scanf("%d %d", &numero1, &numero2);

    //PROCESSAMENTO
    int maior = max(numero1, numero2);

    //SAIDA
    printf("%d \n", maior);

    return EXIT_SUCCESS;
}
