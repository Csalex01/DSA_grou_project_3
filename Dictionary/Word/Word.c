//
// Created by csill on 5/19/2021.
//

#include "Word.h"

Word* createWord(char* ENG, char* HUN) {
    Word* word = (Word*)malloc(sizeof(Word));

    if(!word) {
        printf("Error while allocating memroy for Word!");
        return NULL;
    }

    strcpy(word->ENG, ENG);
    strcpy(word->HUN, HUN);

    return word;
}


void printWord(Word* word) {
    printf("%s => %s\n", word->ENG, word->HUN);
}


void destroyWord(Word* word) {
    free(word);
    word = NULL;
}