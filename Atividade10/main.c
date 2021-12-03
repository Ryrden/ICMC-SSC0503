#include <stdio.h>
#include <stdlib.h>
#define EMPTY (-300)

typedef unsigned int integer;

integer SondagemLinear(integer element, int tentativa, int Table_capacity);
void remove_hash(integer *hash, integer element, int Table_capacity);
void insert_hash(integer *hash, integer element, int Table_capacity);
int search_hash(integer *hash, integer element, int Table_capacity);
integer *create_hash(int Table_capacity);

int main(void) {

    int Table_capacity;
    scanf("%d", &Table_capacity);

    integer *hash = create_hash(Table_capacity);
    integer num;

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%ud", &num);
        insert_hash(hash, num, Table_capacity);
    }

    int D;
    scanf("%d", &D);
    for (int i = 0; i < D; i++) {
        scanf("%ud", &num);
        remove_hash(hash, num, Table_capacity);
    }

    int B;
    scanf("%d", &B);
    for (int i = 0; i < B; i++) {
        scanf("%ud", &num);
        printf("%d ", search_hash(hash, num, Table_capacity));
    }

    free(hash);
    return 0;
}

// h(pos ,i ) = (h’(pos) + i) % M
integer SondagemLinear(integer element, int i, int Table_capacity) {
    return (element + i) % Table_capacity;
}

void insert_hash(integer *hash, integer element, int Table_capacity) {
    int tentativa = 0;
    while (tentativa < Table_capacity) {
        int pos = SondagemLinear(element, tentativa, Table_capacity);
        if (hash[pos] == element) {
            return;
        } else if (hash[pos] == EMPTY) {
            hash[pos] = element;
            return;
        }
        tentativa++;
    }
    return;
}

int search_hash(integer *hash, integer element, int Table_capacity) {
    for (int i = 0; i < Table_capacity; i++) {
        int pos = SondagemLinear(element, i, Table_capacity);
        if (hash[pos] == element)
            return pos;
        else if (hash[pos] == EMPTY)
            return -1;
    }
    return -1;
}

void remove_hash(integer *hash, integer element, int Table_capacity) {
    int pos = search_hash(hash, element, Table_capacity);
    if (pos != -1)
        hash[pos] = EMPTY;
    return;
}

// inicializa tabela HASH com código "EMPTY" como endereço vazio
integer *create_hash(int Table_capacity) {
    integer *hash = (integer *)malloc(sizeof(integer) * Table_capacity);
    if (hash == NULL) {
        printf("Deu merda");
        exit(-1);
    }
    for (int i = 0; i < Table_capacity; i++)
        hash[i] = EMPTY;

    return hash;
}
