#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *substring(char *string, int tamanho);
static int is_substring(char *string, char *substring);
static int min(int a, int b);
static int calcula_overlap(char *prefixo, char *sufixo);
static int **cria_matriz_overlaps(char **reads, int n);
static char **reads_reduzido(char **reads, int *n);

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

    while (n > 1) {
        reads = reads_reduzido(reads, &n);
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", reads[i]);
    }

    return 0;
}

char *substring(char *string, int tamanho) {
    char *resultado = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    if (resultado != NULL && tamanho <= strlen(string)) {
        strcpy(resultado, string);
        resultado[tamanho] = '\0';
    }
    return resultado;
}

int is_substring(char *string, char *substring) {
    int szString = strlen(string);
    int szSubString = strlen(substring);
    int i, j;

    for (i = 0; i <= szString - szSubString; i++) {
        for (j = 0; j < szSubString; j++) {
            if (string[i + j] != substring[j]) {
                break;
            }
        }
        if (j == szSubString) {
            return 1;
        }
    }
    return 0;
}

int min(int a, int b) {
    return ((a < b) ? a : b);
}

int calcula_overlap(char *str1, char *str2) {
    int max = -1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int menorTamanho = min(len1, len2);
    if (len2 <= len1) {
        if (is_substring(str1, str2)) {
            return len2;
        }
    }

    for (int i = 1; i <= menorTamanho; i++) {
        char *subStr = substring(str2, i);
        if (strcmp(&str1[len1 - i], subStr) == 0) {
            if (max < i) {
                max = i;
            }
        }
        free(subStr);
    }

    return max;
}

int **cria_matriz_overlaps(char **reads, int n) {
    int **matriz_Overlaps;
    // Inicializa a matriz de contagem de overlaps
    matriz_Overlaps = (int **)malloc(sizeof(int *) * n);
    if (matriz_Overlaps == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        matriz_Overlaps[i] = (int *)malloc(sizeof(int) * n);
        if (matriz_Overlaps[i] == NULL) {
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            matriz_Overlaps[i][j] = -1;
        }
    }

    // Preenche a matriz de contagem de overlaps
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matriz_Overlaps[i][j] = calcula_overlap(reads[i], reads[j]);
            }
        }
    }
    return matriz_Overlaps;
}

char **reads_reduzido(char **reads, int *n) {
    char **resultado;
    int **matriz_overlaps = cria_matriz_overlaps(reads, *n);
    char *strConcatenado;
    int size = *n;
    int strPos1 = 0;
    int strPos2 = 1;
    int max = -1;

    if (matriz_overlaps == NULL) {
        return NULL;
    }
    resultado = (char **)malloc(sizeof(char *) * (size - 1));
    if (resultado == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (max < matriz_overlaps[i][j]) {
                max = matriz_overlaps[i][j];
                strPos1 = i;
                strPos2 = j;
            }
        }
    }
    int sizeStrConcatenado;
    if (max > -1) {
        sizeStrConcatenado = strlen(reads[strPos1]) + strlen(&reads[strPos2][max]) + 1;
    } else {
        sizeStrConcatenado = strlen(reads[strPos1]) + strlen(reads[strPos2]) + 1;
    }
    strConcatenado = (char *)malloc(sizeof(char) * sizeStrConcatenado);
    if (strConcatenado == NULL) {
        return NULL;
    }
    strConcatenado[0] = '\0';
    strConcatenado = strcat(strConcatenado, reads[strPos1]);
    if (max > -1) {
        strConcatenado = strcat(strConcatenado, &reads[strPos2][max]);
    } else {
        strConcatenado = strcat(strConcatenado, reads[strPos2]);
    }
    resultado[0] = (char *)malloc(sizeof(char) * (strlen(strConcatenado) + 1));
    strcpy(resultado[0], strConcatenado);
    free(strConcatenado);
    strConcatenado = NULL;

    int k = 1;
    for (int i = 0; i < size; i++) {
        if (i != strPos1 && i != strPos2) {
            resultado[k] = (char *)malloc(sizeof(char) * (strlen(reads[i]) + 1));
            if (resultado[k] == NULL) {
                return NULL;
            }
            strcpy(resultado[k], reads[i]);
            k++;
        }
    }
    *n = size - 1;
    return resultado;
}
