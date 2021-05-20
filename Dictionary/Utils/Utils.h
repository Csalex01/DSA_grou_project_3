#ifndef DICTIONARY_UTILS_H
#define DICTIONARY_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Word/Word.h"
#include "../Array/Array.h"
#include "../LinkedList/LinkedList.h"

/// Data structures
Word** WORDS;
ListNode* LINKED_LIST;

/// Counters
int WORD_COUNT;

/// Utility functions
void readDictionary(char* fileName);

/// Other functions
void fixString(char* string);


#endif //DICTIONARY_UTILS_H
