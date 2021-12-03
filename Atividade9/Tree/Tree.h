#ifndef TREE_H
#define TREE_H
#include "../Util/util.h"
#include "../numbers/number.h"

#define LEFT 0
#define RIGHT 1

typedef struct binary_tree_st BINARY_TREE;

BINARY_TREE *create_tree();
boolean insert_tree(BINARY_TREE *tree, NUMBER *item) ;
boolean erase_tree(BINARY_TREE **tree);
NUMBER *abb_busca(BINARY_TREE *T, int chave);

#endif // TREE_H