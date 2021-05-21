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