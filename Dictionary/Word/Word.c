#include "Word.h"
#include "../Utils/Utils.h"

Word *createWord(char *ENG, char *HUN) {
    Word *word = (Word *) malloc(sizeof(Word));

    if (!word) {
        printf("Error while allocating memory for Word!");
        return NULL;
    }

    strcpy(word->ENG, ENG);
    strcpy(word->HUN, HUN);

    return word;
}


void printWord(Word *word) {
    printf("%s (%i) => %s (%i)\n", word->ENG, stringToInt(word->ENG), word->HUN, stringToInt(word->HUN));
}

void printWords() {
    for (int i = 0; i < WORD_COUNT; i++)
        printWord(ARRAY[i]);
}

void destroyWord(Word *word) {
    free(word);
    word = NULL;
}