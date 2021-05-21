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

struct ListNode *searchInLinkedList(char *word) {
    fixString(word);

    struct ListNode *p = LINKED_LIST;

    while (p != NULL && !(!strcmp(p->data->ENG, word) || !strcmp(p->data->HUN, word)))
        p = p->next;


    return p;
}

char *lookupLinkedListENG(char *HUN) {
    fixString(HUN);

    struct ListNode *p = LINKED_LIST;

    while (p != NULL && strcmp(p->data->HUN, HUN))
        p = p->next;

    if (p == NULL)
        return NULL;

    return p->data->ENG;
}

char *lookupLinkedListHUN(char *ENG) {
    fixString(ENG);

    struct ListNode *p = LINKED_LIST;

    while (p != NULL && strcmp(p->data->ENG, ENG))
        p = p->next;

    if (p == NULL)
        return NULL;

    return p->data->HUN;
}

char *lookupLinkedList(char *word) {
    fixString(word);

    char *ENG = lookupLinkedListENG(word);

    char *HUN = lookupLinkedListHUN(word);

    if (HUN)
        return HUN;

    if (ENG)
        return ENG;

    return NULL;
}

void insertIntoLinkedList(ListNode **linkedList, Word *data, int index) {
    ListNode *newNode = createListNode();
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = *linkedList;

    if (linkedList == NULL || index == 0) {
        newNode->next = *linkedList;
        *linkedList = newNode;
    } else {
        struct ListNode *p = *linkedList;
        int i = 1;

        while (p->next != NULL && i < index) {
            p = p->next;
            i++;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
}

void traverseLinkedList(ListNode *linkedList) {
    if (linkedList == NULL) {
        printf("\n");
        return;
    }

    printWord(linkedList->data);
    traverseLinkedList(linkedList->next);
}


void deleteFromLinkedList(char *word) {
    ListNode *p = LINKED_LIST;
    ListNode *e = NULL;

    while (p != NULL && !(!strcmp(p->data->ENG, word) || !strcmp(p->data->HUN, word))) {
        e = p;
        p = p->next;
    }

    if (p != NULL) {
        if (e == NULL) {
            LINKED_LIST = p->next;
        } else {
            e->next = p->next;
        }

        free(p);
    }
}

void destroyLinkedList(ListNode *linkedList) {
    if (linkedList->next)
        destroyLinkedList(linkedList->next);

    free(linkedList);
    linkedList = NULL;
}