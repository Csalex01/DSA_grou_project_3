#include "Menu.h"
#include "../Utils/Utils.h"

/// Main menu
void activateMenu() {
    int choice;

    while (true) {
        printf("\n");
        printf("==========> Dictionary <===========\n");
        printf("            -> MENU <-           \n\n");
        printf("> 1. Array Operations              \n");
        printf("> 2. Dynamic Linked List Operations\n");
        printf("> 3. Binary Search Tree Operations \n");
        printf("> 4. Heap Operations               \n");
        printf("> 5. Hash Table Operations         \n");
        printf("> 6. Exit                          \n");
        printf("<--------------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                arrayOperations();
                break;

            case 2:
                dynamicLinkedListOperations();
                break;

            case 3:
                binarySearchTreeOperations();
                break;

            case 4:
                heapOperations();
                break;

            case 5:
                hashTableOperations();
                break;

            case 6:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

/// Submenus
void arrayOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> Dictionary <========\n");
        printf("         -> ARRAY <-        \n\n");
        printf("> 1. Print words              \n");
        printf("> 2. Lookup a word            \n");
        printf("> 3. Back to main menu        \n");
        printf("> 4. Exit                     \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                printWords();
                break;

            case 2:
                arrayOperations_lookup();
                break;

            case 3:
                activateMenu();
                break;

            case 4:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

void dynamicLinkedListOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> Dictionary <========\n");
        printf("  -> Dynamic Linked List <- \n\n");
        printf("> 1. Print words              \n");
        printf("> 2. Lookup a word            \n");
        printf("> 3. Back to main menu        \n");
        printf("> 4. Exit                     \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                traverseLinkedList(LINKED_LIST);
                break;

            case 2:
                dynamicLinkedListOperations_lookup();
                break;

            case 3:
                activateMenu();
                break;

            case 4:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

void binarySearchTreeOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> Dictionary <========    \n");
        printf("  -> Binary Search Tree <-      \n\n");
        printf("> 1. Print words                  \n");
        printf("> 2. Lookup a word                \n");
        printf("> 3. Insert                       \n");
        printf("> 4. Delete from Binary Search Tree\n");
        printf("> 5. Back to main menu            \n");
        printf("> 6. Exit                         \n");
        printf("<---------------------------->    \n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                traverseBinarySearchTree(BST);
                break;

            case 2:
                binarySearchTree_lookup();
                break;

            case 3:
                printf("Kell insert....?!");
                break;

            case 4:
                printf("Error");
                break;
            case 5:
                activateMenu();
                break;

            case 6:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

void heapOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> Dictionary <========\n");
        printf("->          Heap           <- \n\n");
        printf("> 1. Print words              \n");
        printf("> 2. Heap sort(Error)         \n");
        printf("> 3. Back to main menu        \n");
        printf("> 4. Exit                     \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                printHeap();
                break;

            case 2:
                heapSort();
                break;

            case 3:
                activateMenu();
                break;

            case 4:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

void hashTableOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> Dictionary <========\n");
        printf("->        Hash table           <- \n\n");
        printf("> 1. Print words              \n");
        printf("> 2. Search                   \n");
        printf("> 3. Delete                   \n");
        printf("> 4. Back to main menu        \n");
        printf("> 5. Exit                     \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                printHashTable();
                break;

            case 2:
                searchInHashTable();
                break;

            case 3:
                DeleteFromHashTable();
                break;

            case 4:
                activateMenu();
                break;

            case 5:
                printf("=========> Goodbye! <=========\n");
                exit(0);

            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

/// Helper functions

void arrayOperations_lookup() {
    char tmp[30];

    printf("The word you're looking for: ");
    scanf("%s", tmp);

    printf("%s => %s", tmp, lookupArray(tmp));
}

void dynamicLinkedListOperations_lookup() {
    char tmp[30];

    printf("The word you're looking for: ");
    scanf("%s", tmp);

    printf("%s => %s", tmp, lookupLinkedList(tmp));
}

void binarySearchTree_lookup() {
    char tmp[30];
    int tmp2 = 0;

    printf("Valassza ki, hogy milyen nyelven akar keresni:\n");
    printf("\t1. Magyar\n");
    printf("\t2. Angol\n");
    scanf("%i", &tmp2);

    switch (tmp2) {
        case 1:
            printf("\nAdd meg a szavat magyarul:");
            scanf("%s", tmp);
            printf("%s => %s", tmp, lookupBinarySearchTreeENG(BST, tmp));
            break;

        case 2:
            printf("\nAdd meg a szavat angolul:");
            scanf("%s", tmp);
            printf("%s => %s", tmp, lookupBinarySearchTreeHUN(BST, tmp));
            break;
    }

}

void searchInHashTable() {
    char tmp[30];

    printf(" Add meg a szavat:");
    scanf("%s", tmp);
    printWord(searchHashTable(tmp));

}

void DeleteFromHashTable(){
    char tmp[30];

    printf(" Add meg a szavat:");
    scanf("%s", tmp);

   deleteFromHashTable(tmp);

}

