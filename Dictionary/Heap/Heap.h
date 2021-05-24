#ifndef DICTIONARY_HEAP_H
#define DICTIONARY_HEAP_H

#include "../Utils/Utils.h"

typedef struct Heap {
    Word **data;
    int size;
    int maxSize;
} Heap;

struct Heap *createHeap(int size);

Word* deleteMaxFromHeap();

void insertIntoHeap(Word *word);

void up(int i);

void down(int i);

void heapSort();

void printHeap();

#endif //DICTIONARY_HEAP_H