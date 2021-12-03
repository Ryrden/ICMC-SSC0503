#include "number.h"
#include <stdio.h>
#include <stdlib.h>

struct number_st {
    int key;
};

NUMBER *create_item(int num) {
    NUMBER *numero;
    numero = (NUMBER*) malloc(sizeof(NUMBER)); 
    if (numero == NULL)
        exit(-1);

    numero->key = num;
    return numero;
}

int get_key(NUMBER *num) {
    return num->key;
}