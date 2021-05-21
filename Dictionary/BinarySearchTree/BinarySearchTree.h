//
// Created by csill on 5/21/2021.
//

#ifndef DICTIONARY_BINARYSEARCHTREE_H
#define DICTIONARY_BINARYSEARCHTREE_H

#include "../Utils/Utils.h"

typedef struct BinarySearchTree {
    Word *data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} BinarySearchTree;

struct BinarySearchTree *createBinarySearchTree(Word *word);

struct BinarySearchTree *deleteFromBinarySearchTree(struct BinarySearchTree *Tree, Word *word);

struct BinarySearchTree *minValueBinarySearchTree(struct BinarySearchTree *Tree);

char *lookupBinarySearchTreeENG(struct BinarySearchTree *Tree, char *HUN);

char *lookupBinarySearchTreeHUN(struct BinarySearchTree *Tree, char *ENG);

char *lookupBinarySearchTree(char *word);

void insertIntoBinaryTree(struct BinarySearchTree **Tree, Word *word);

void traverseBinarySearchTree(struct BinarySearchTree *Node);

#endif //DICTIONARY_BINARYSEARCHTREE_H
