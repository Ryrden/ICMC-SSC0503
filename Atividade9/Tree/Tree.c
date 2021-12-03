#include "Tree.h"
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    NUMBER *item;
    NODE *right;
    NODE *left;
};

struct binary_tree_st {
    NODE *root;
    int depth;
};

static void erase_tree_nodes(NODE **root);
static NODE *create_tree_node(NUMBER *item);
static NODE *insert_tree_node(NODE *root, NUMBER *item);
static boolean isBigger(NUMBER *item, NODE *root);
static boolean isSmaller(NUMBER *item, NODE *root);
static NUMBER *abb_busca_no(NODE *raiz, int chave);

BINARY_TREE *create_tree() {
    BINARY_TREE *tree;
    tree = (BINARY_TREE *)malloc(sizeof(BINARY_TREE));
    if (tree != NULL) {
        tree->root = NULL;
        tree->depth = -1;
        return tree;
    }
    return NULL;
}

static NODE *create_tree_node(NUMBER *item) {
    if (item != NULL) {
        NODE *new_item;
        new_item = (NODE *)malloc(sizeof(NODE));
        if (new_item == NULL)
            exit(EXIT_FAILURE);
        new_item->item = item;
        new_item->left = NULL;
        new_item->right = NULL;
        return new_item;
    }
    return NULL;
}

boolean erase_tree(BINARY_TREE **tree) {
    if (tree != NULL) {
        erase_tree_nodes(&(*tree)->root);
        free(*tree);
        tree = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean insert_tree(BINARY_TREE *tree, NUMBER *item) {
    return ((tree->root = insert_tree_node(tree->root, item)) != NULL);
}

static NODE *insert_tree_node(NODE *root, NUMBER *item) {
    if (root == NULL)
        root = create_tree_node(item);
    else if (isBigger(item, root))
        root->right = insert_tree_node(root->right, item);
    else if (isSmaller(item, root))
        root->left = insert_tree_node(root->left, item);
    return root;
}

static boolean isBigger(NUMBER *item, NODE *root) {
    return get_key(item) > get_key(root->item);
}
static boolean isSmaller(NUMBER *item, NODE *root) {
    return get_key(item) < get_key(root->item);
}

static void erase_tree_nodes(NODE **root) {
    if (*root != NULL) {
        erase_tree_nodes(&(*root)->left);
        erase_tree_nodes(&(*root)->right);
        free((*root)->item);
        (*root)->item = NULL;
        free(*root);
        root = NULL;
    }
}

static NUMBER *abb_busca_no(NODE *raiz, int chave){
    if(raiz == NULL)
        return NULL;
    if(chave == get_key(raiz->item))
        return (raiz->item);
    if(chave < get_key(raiz->item))
        return (abb_busca_no(raiz->left, chave));
    else
        return (abb_busca_no(raiz->right, chave));
}
NUMBER *abb_busca(BINARY_TREE *T, int chave){
    return(abb_busca_no(T->root, chave));
}


