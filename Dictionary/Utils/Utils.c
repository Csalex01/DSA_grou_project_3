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

    WORD_COUNT = n;

    WORDS = (Word**)malloc(n * sizeof(Word*));

    char HUN[30];
    char ENG[30];

    for (int i = 0; i < WORD_COUNT; i++) {
        fscanf(fin, "%s", ENG);
        fscanf(fin, "%s", HUN);

        insertIntoArray(createWord(ENG, HUN), i);
        insertIntoLinkedList(&LINKED_LIST, createWord(ENG, HUN), i);
    }
}

