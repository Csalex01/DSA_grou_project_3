#include "../Utils/Utils.h"

struct BinarySearchTree *createBinarySearchTree(Word *word) {
    struct BinarySearchTree *Tree = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));

    if (!Tree) {
        printf("Error while allocating memory for BinarySearchTree!");
        return NULL;
    }

    Tree->data = word;
    Tree->left = NULL;
    Tree->right = NULL;

    return Tree;
}

struct BinarySearchTree *minValueBinarySearchTree(struct BinarySearchTree *pTree);

struct BinarySearchTree *deleteFromBinarySearchTree(struct BinarySearchTree *Tree, Word *word) {
    if (Tree == NULL || word == NULL)
        return NULL;

    if (stringToInt(Tree->data->ENG) > stringToInt(word->ENG))
        Tree->left = deleteFromBinarySearchTree(Tree->left, word);

    else if (stringToInt(word->ENG) > stringToInt(Tree->data->ENG))
        Tree->right = deleteFromBinarySearchTree(Tree->right, word);

    else {
        if (Tree->left == NULL) {
            struct BinarySearchTree *tmp = Tree->right;
            free(Tree);
            return tmp;
        } else if (Tree->right == NULL) {
            struct BinarySearchTree *tmp = Tree->left;
            free(Tree);
            return tmp;
        }

        struct BinarySearchTree *tmp = minValueBinarySearchTree(Tree->right);

        Tree->data = tmp->data;

        Tree->right = deleteFromBinarySearchTree(Tree->right, tmp->data);
    }

    return Tree;
}

struct BinarySearchTree *minValueBinarySearchTree(struct BinarySearchTree *Tree) {
    struct BinarySearchTree *current = Tree;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

char *lookupBinarySearchTreeENG(struct BinarySearchTree *Tree, char *HUN) {
    if (!Tree)
        return NULL;

    fixString(HUN);

    if (!strcmp(Tree->data->HUN, HUN))
        return Tree->data->ENG;

    if (Tree->left)
        return lookupBinarySearchTreeENG(Tree->left, HUN);

    if (Tree->right)
        return lookupBinarySearchTreeENG(Tree->right, HUN);
}

char *lookupBinarySearchTreeHUN(struct BinarySearchTree *Tree, char *ENG) {
    if (!Tree)
        return NULL;

    fixString(ENG);

    if (!strcmp(Tree->data->ENG, ENG))
        return Tree->data->HUN;

    if (Tree->left)
        return lookupBinarySearchTreeHUN(Tree->left, ENG);

    if (Tree->right)
        return lookupBinarySearchTreeHUN(Tree->right, ENG);
}

char *lookupBinarySearchTree(char *word) {
    fixString(word);

    char* ENG = lookupBinarySearchTreeENG(BST, word);
    char* HUN = lookupBinarySearchTreeHUN(BST, word);

    if (HUN)
        return HUN;

    if (ENG)
        return ENG;

    return NULL;
}

void insertIntoBinaryTree(struct BinarySearchTree **Tree, Word *word) {
    if ((*Tree) == NULL) {
        *Tree = createBinarySearchTree(word);
    } else {
        if (stringToInt((*Tree)->data->ENG) > stringToInt(word->ENG))
            insertIntoBinaryTree(&((*Tree)->left), word);
        else
            insertIntoBinaryTree(&((*Tree)->right), word);
    }
}

void traverseBinarySearchTree(struct BinarySearchTree *Node) {
    if (Node->left)
        traverseBinarySearchTree(Node->left);

    printWord(Node->data);

    if (Node->right)
        traverseBinarySearchTree(Node->right);
}