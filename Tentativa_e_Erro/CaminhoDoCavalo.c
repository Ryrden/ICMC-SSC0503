#include <stdio.h>
#include <stdlib.h>
#define EMPTY (-1)

int _valido(int **tabuleiro, int lin, int col, int x, int y) {
    if (x < 0 || x >= lin || y < 0 || y >= col)
        return 0; // se sair do espaço tabuleiro, não é válido
    else if (tabuleiro[x][y] != EMPTY)
        return 0; // se a posição estiver ocupada, não é válido
    return 1;
}

// imprimindo o caminho do cavalo
void printTabuleiro(int **tabuleiro, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (tabuleiro[i][j] == EMPTY)
                printf(" *** ");
            else
                printf(" %3d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Toda a estrutura de tentativa e erro vai ser parecida com isso aqui.
/* O que muda é:
1- o teste para saber se acabou o programa
2- a maneira de gerar tentativas
3- a maneira de conferir se a tentativa é válida ou não
4- a maneira de desfazer a tentativa */
int _caminho(int **tabuleiro, int lin, int col, int qnt_cavalo, int x, int y) {
    printTabuleiro(tabuleiro, lin, col); // tabuleiro intermediário
    // tabuleiro está pronto, cavalo conseguiu!
    if (qnt_cavalo >= lin * col) {
        return 1;
    }
    // possibilidade de pulos do cavalo
    int pulos[][2] = {
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1}};
    for (int i = 0; i < 8; i++) {
        // gerando próximos passos de pulo
        int novo_x = x + pulos[i][0];
        int novo_y = y + pulos[i][1];
        //É válido esse pulo?
        if (_valido(tabuleiro, lin, col, novo_x, novo_y)) {
            tabuleiro[novo_x][novo_y] = qnt_cavalo + 1;
            // continua executando
            if (_caminho(tabuleiro, lin, col, qnt_cavalo + 1, novo_x, novo_y)) {
                return 1;
            }
            // Backtracking = Deu merda, bora voltar ae!!
            tabuleiro[novo_x][novo_y] = EMPTY;
        }
    }
    // testou todas as possibilidades e não deu certo, não tem solução
    return 0;
}

int caminho(int **tabuleiro, int n, int m) {
    tabuleiro[0][0] = 1;
    return _caminho(tabuleiro, n, m, 1, 0, 0);
}

int main(int argc, char *argv[]) {
    // testando para tabuleiro 3x3
    int lin = 3;
    int col = 3;
    // criando tabuleiro
    int **tabuleiro = malloc(sizeof(int *) * lin);
    for (int i = 0; i < lin; i++) {
        tabuleiro[i] = malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++)
            tabuleiro[i][j] = EMPTY;
    }
    caminho(tabuleiro, lin, col);
    printf("caminho %d x %d\n", lin, col);
    printTabuleiro(tabuleiro, lin, col);
    return 0;
}
