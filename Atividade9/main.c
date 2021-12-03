#include "Tree/Tree.h"
#include "numbers/number.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    BINARY_TREE *tree;
    tree = create_tree();

    int N;
    scanf("%d", &N);

    int *vetor = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%d", &vetor[i]);

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int random = rand() % N;
        int tmp = vetor[i];
        vetor[i] = vetor[random];
        vetor[random] = tmp;
    }

    for (int i = 0; i < N; i++) {
        NUMBER *num = create_item(vetor[i]);
        insert_tree(tree, num);
    }

    int K;
    scanf("%d", &K);

    int *Kvet = (int *)malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &Kvet[i]);
    }

    for (int i = 0; i < K; i++) {
        if (abb_busca(tree, Kvet[i]) != NULL)
            printf("1\n");
        else
            printf("0\n");
    }

    free(Kvet);
    free(vetor);
    erase_tree(&tree);
    return 0;
}