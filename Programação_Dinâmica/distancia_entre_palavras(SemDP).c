#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esse algoritmo é extremamente ineficiente
int dist(char *str1, char *str2) {
    if (*str1 == '\0')
        return strlen(str2);
    else if (*str2 == '\0')
        return strlen(str1);

    if (*str1 == *str2) {
        return dist(str1 + 1, str2 + 1);
    } else {
        int r1 = dist(str1 + 1, str2 + 1) + 1;
        int r2 = dist(str1 + 1, str2) + 1;
        int r3 = dist(str1, str2 + 1) + 1;
        if (r1 < r2)
            if (r1 < r3)
                return r1;
            else
                return r3;
        else if (r2 < r3)
            return r2;
        else
            return r3;
    }

    return 0;
}

int main() {
    char *str1 = "adenilso";
    char *str2 = "admilson";
    int d = dist(str1, str2);
    printf("a distancia entre '%s' e '%s' eh: %d\n", str1, str2, d);
    system("pause");
    return 0;
}