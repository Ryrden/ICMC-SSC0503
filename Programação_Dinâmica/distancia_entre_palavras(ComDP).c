#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y) {
    if (x > y)
        return y;
    return x;
}

// Esse algoritmo é extremamente ineficiente
int _dist(int **cache, char *str1, int p1, char *str2, int p2) {
    if (cache[p1][p2] == -1) {
        int res;
        if (str1[p1] == '\0')
            res = strlen(str2) - p2;
        else if (str2[p2] == '\0')
            res = strlen(str1) - p1;
        else {
            if (str1[p1] == str2[p2]) {
                res = _dist(cache, str1, p1 + 1, str2, p2 + 1);
            } else {
                int r1 = _dist(cache, str1, p1 + 1, str2, p2 + 1) + 1;
                int r2 = _dist(cache, str1, p1 + 1, str2, p2) + 1;
                int r3 = _dist(cache, str1, p1, str2, p2 + 1) + 1;
                res = min(r1, min(r2, r3));
            }
        }
        cache[p1][p2] = res;
    }
    return cache[p1][p2];
}

int dist(char *s1, char *s2) {
    int **cache;
    int l1 = strlen(s1) + 1;
    int l2 = strlen(s2) + 1;
    cache = malloc(sizeof(int *) * l1);
    for (int i = 0; i < l1; i++) {
        cache[i] = malloc(sizeof(int) * l2);
        for (int j = 0; j < l2; j++) {
            cache[i][j] = -1;
        }
    }
    int res = _dist(cache, s1, 0, s2, 0);

    return _dist(cache, s1, 0, s2, 0);
}

int main() {
    char *str1 = "Pedro de Alcantara Joao Carlos Leopoldo Salvador Bibiano Francisco Xavier de Paula Leocaio Miguel Gabriel Rafael Gonzaga de Braganca e Bourbon";
    char *str2 = "Pedro de Alcantara Francisco Antonio Joao Carlos Xavier de Paula Miguel Rafael Joaquim Jose Gonzaga Pascoal Cipriano Serafim de Braganca e Bourbon ";
    int d = dist(str1, str2);
    printf("a distancia entre: '%s' \ne: '%s' \n\n eh: %d\n\n", str1, str2, d);
    system("pause");
    return 0;
}