#include "../Utils/Utils.h"

struct ListNode *createListNode() {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));

    if (!node) {
        printf("Error while allocating memory for ListNode!");
        return NULL;
    }

    node->next = NULL;
    node->data = NULL;

    return node;
}

void insertIntoLinkedList(ListNode** linkedList, Word *data, int index) {
    ListNode *newNode = createListNode();
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = *linkedList;

    if (linkedList == NULL || index == 0) {
        newNode->next = *linkedList;
        *linkedList = newNode;
    } else {
        struct ListNode* p = *linkedList;
        int i = 1;

        while (p->next != NULL && i < index) {
            p = p->next;
            i++;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
}

void traverseLinkedList(ListNode* linkedList) {
    if(linkedList == NULL) {
        printf("\n");
        return;
    }

    printWord(linkedList->data);
    traverseLinkedList(linkedList->next);
}