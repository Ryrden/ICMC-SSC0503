#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substring(char *string, int tamanho) {
    char *resultado = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    if (resultado != NULL && tamanho <= strlen(string)) {
        strcpy(resultado, string);
        resultado[tamanho] = '\0';
    }
    return resultado;
}


int main() {
    int n;
    char line[1000];
    char *str;
    char **reads;

    // Lê quantidade de reads
    scanf("%d", &n);
    getchar();
    reads = (char **)malloc(sizeof(char *) * n);
    // Lê a entrada do usuário
    for (int i = 0; i < n; i++) {
        fgets(line, 1000, stdin);
        str = substring(line, strlen(line) - 1);
        reads[i] = str;
    }

    char *string = max_string_overlap(reads, n);

    return EXIT_SUCCESS;
}