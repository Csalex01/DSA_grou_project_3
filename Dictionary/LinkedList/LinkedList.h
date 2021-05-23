#ifndef DICTIONARY_LINKEDLIST_H
#define DICTIONARY_LINKEDLIST_H

#include "../Utils/Utils.h"

typedef struct ListNode {
    struct ListNode *next;
    Word *data;
} ListNode;

struct ListNode *createListNode();

struct ListNode *searchInLinkedList(char *word);

char* lookupLinkedListENG(char *HUN);

char* lookupLinkedListHUN(char *ENG);

char *lookupLinkedList(char *word);

void insertIntoLinkedList(ListNode **linkedList, Word *data, int index);

void traverseLinkedList(ListNode *linkedList);

void deleteFromLinkedList(char *word);

void destroyLinkedList(ListNode *linkedList);

#endif //DICTIONARY_LINKEDLIST_H
