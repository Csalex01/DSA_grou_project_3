//
// Created by csill on 5/22/2021.
//

#ifndef DICTIONARY_HEAP_H
#define DICTIONARY_HEAP_H

#include "../Word/Word.h"

typedef struct Heap {
    Word** data;
    int size;
    int maxSize;
} Heap;

struct Heap* createHeap(int size);

#endif //DICTIONARY_HEAP_H
