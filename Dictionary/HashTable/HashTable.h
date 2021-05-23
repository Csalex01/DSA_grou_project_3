#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include "../Utils/Utils.h"

Word* searchHashTable(char* word);

void printHashTable();

void insertIntoHashTable(Word* word);

void deleteFromHashTable(char* word);

#endif //DICTIONARY_HASHTABLE_H
