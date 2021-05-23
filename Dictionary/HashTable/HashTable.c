#include "HashTable.h"

Word *searchHashTable(char *word) {
    int key = stringToInt(word);

    int i = 0;
    int j;

    do {
        j = (key + i) % WORD_COUNT;

        if (stringToInt(HASH_TABLE[j]->ENG) == key ||
            stringToInt(HASH_TABLE[j]->HUN) == key)
            return HASH_TABLE[j];

        else
            i++;

    } while (HASH_TABLE[j] != NULL && i != WORD_COUNT);

    printf("Element not found!");

    return NULL;
}

void insertIntoHashTable(Word *word) {
    int key = stringToInt(word->ENG);

    int i = 0;
    int j;

    do {
        j = (key + i) % WORD_COUNT;

        if (HASH_TABLE[j] == NULL) {

            HASH_TABLE[j] = word;
            return;

        } else i++;
    } while (i != WORD_COUNT);

    printf("HashTable overflow!");
}

void printHashTable() {
    for (int i = 0; i < WORD_COUNT; i++)
        if (HASH_TABLE[i] != NULL)
            printWord(HASH_TABLE[i]);
    printf("\n");
}

void deleteFromHashTable(char *word) {
    int key = stringToInt(word);

    int i = 0;
    int j;

    do {
        j = (key + i) % WORD_COUNT;

        if (stringToInt(HASH_TABLE[j]->ENG) == key ||
            stringToInt(HASH_TABLE[j]->HUN) == key) {

            HASH_TABLE[j] = NULL;
            return;

        } else i++;

    } while (HASH_TABLE[j] != NULL && i != WORD_COUNT);

    if (i != WORD_COUNT)
        printf("Element not found!");
}