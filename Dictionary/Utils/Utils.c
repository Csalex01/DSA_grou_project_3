#include "Utils.h"
#include "../Array/Array.h"

void readDictionary(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Could not open file %s", fileName);
        return;
    }

    int n;
    fscanf(fin, "%i", &n);

    /// TODO Change WORD_COUNT back to n!
    WORD_COUNT = 20;

    ARRAY = (Word **) malloc(WORD_COUNT * sizeof(Word *));
    HASH_TABLE = (Word **) malloc(WORD_COUNT * sizeof(Word *));
    HEAP = createHeap(n);

    char HUN[30];
    char ENG[30];

    for(int i = 0; i < WORD_COUNT; i++) {
        HASH_TABLE[i] = NULL;
    }

    for (int i = 0; i < WORD_COUNT; i++) {
        fscanf(fin, "%s", ENG);
        fscanf(fin, "%s", HUN);

        insertIntoArray(createWord(ENG, HUN), i);
        insertIntoLinkedList(&LINKED_LIST, createWord(ENG, HUN), i);
        insertIntoBinaryTree(&BST, createWord(ENG, HUN));
        insertIntoHashTable(createWord(ENG, HUN));
        insertIntoHeap(createWord(ENG, HUN));
    }
}

void toLower(char *word) {
    for (int i = 0; i < strlen(word); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = (char) (word[i] + 32);
}

void toUpper(char *word) {
    for (int i = 0; i < strlen(word); i++)
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= 32;
}

int stringToInt(char *word) {
    int sum = 0;

    char tmp[30];

    strcpy(tmp, word);

    toUpper(tmp);

    for (int i = 0; i < strlen(tmp); i++) {
        int n = ((int) tmp[i]) - 64;
        sum += n * n;
    }

    return sum;
}