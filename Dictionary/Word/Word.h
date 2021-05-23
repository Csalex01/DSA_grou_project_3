#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char HUN[30];
    char ENG[30];
} Word;

Word* createWord(char* ENG, char* HUN);

void printWord(Word* word);

void printWords();

void destroyWord(Word* word);

#endif //DICTIONARY_WORD_H
