#include <stdio.h>

int hash (const char *str){
    int h = 0;
    while (*str != '\0')
        h += *str++;
    return h;
}

unsigned int hash (const char *str){
    unsigned int h = 0;
    const int A = 31; //usado com frequência
    while (*str != '\0')
        h = A*h + (*str);
        str++;
    return h;
}
