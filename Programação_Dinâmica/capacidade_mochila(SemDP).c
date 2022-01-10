#include <stdio.h>
#include <stdlib.h>

int peso[] = {5, 3, 4, 6, 4, 1, 4, 3, 5, 6, 7, 2, 1, 3, 4};
int valor[] = {5, 6, 1, 2, 8, 9, 1, 8, 2, 4, 2, 9, 1, 2, 8};

// solução pessima, demora
int mochila(int n, int cap) {
    if (n == 0 || cap == 0) {
        return 0;
    } else {
        int item = n - 1;
        int r1 = mochila(n - 1, cap);
        if (cap >= peso[item]) {
            int r2 = valor[item] + mochila(n - 1, cap - peso[item]);
            if (r1 < r2)
                return r2;
            else
                return r1;

        } else {
            return r1;
        }
    }
    return 0;
}

int main() {
    int n = 10;
    int cap = 10;
    int r = mochila(n, cap);
    printf("para os %d primeiros itens e com a mochila de capacidade %d, o valor maximo eh: %d\n", n, cap, r);
    system("pause");
    return 0;
}