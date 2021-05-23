//
// Created by csill on 5/20/2021.
//

#ifndef DICTIONARY_ARRAY_H
#define DICTIONARY_ARRAY_H

#endif //DICTIONARY_ARRAY_H

#include "../Word/Word.h"

char* lookupArrayENG(char* HUN);

char* lookupArrayHUN(char* ENG);

char* lookupArray(char* word);

void insertIntoArray(Word* word, int index);

void deleteFromArray(int index);