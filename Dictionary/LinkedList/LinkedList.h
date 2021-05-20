#ifndef DICTIONARY_LINKEDLIST_H
#define DICTIONARY_LINKEDLIST_H

#include "../Utils/Utils.h"

typedef struct ListNode {
    struct ListNode *next;
    Word *data;
} ListNode;

struct ListNode *createListNode();

void insertIntoLinkedList(ListNode** linkedList, Word *data, int index);

void traverseLinkedList(ListNode* linkedList);

#endif //DICTIONARY_LINKEDLIST_H
