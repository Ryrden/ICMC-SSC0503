#include <stdio.h>
#include <stdlib.h>

int peso[] = {5, 3, 4, 6, 4, 1, 4, 3, 5, 6, 7, 2, 1, 3, 4};
int valor[] = {5, 6, 1, 2, 8, 9, 1, 8, 2, 4, 2, 9, 1, 2, 8};

// solução pessima, demora
int _mochila(int **cache, int n, int cap) {
    if (cache[n][cap] == -1) {
        int res;
        if (n == 0 || cap == 0) {
            res = 0;
        } else {
            int item = n - 1;
            int r1 = _mochila(cache, n - 1, cap);
            if (cap >= peso[item]) {
                int r2 = valor[item] + _mochila(cache, n - 1, cap - peso[item]);
                if (r1 < r2)
                    res = r2;
                else
                    res = r1;

            } else {
                res = r1;
            }
        }
        cache[n][cap] = res;
    }
    return cache[n][cap];
}

int mochila(int n, int cap) {
    int **cache;
    cache = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        cache[i] = malloc(sizeof(int) * (cap + 1));
        for (int j = 0; j < cap + 1; j++) {
            cache[i][j] = -1;
        }
    }
    int res = _mochila(cache, n, cap);
    for (int i = 0; i < n + 1; i++) {
        free(cache[i]);
    }
    free(cache);
    return res;
}

int main() {
    int n = 10;
    int cap = 10;
    int r = mochila(n, cap);
    printf("para os %d primeiros itens e com a mochila de capacidade %d, o valor maximo eh: %d\n", n, cap, r);
    system("pause");
    return 0;
}