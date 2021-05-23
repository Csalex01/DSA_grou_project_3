//
// Created by csill on 5/22/2021.
//

#include "Heap.h"

struct Heap *createHeap(int size) {
    struct Heap *heap = (struct Heap *) malloc(sizeof(struct Heap *));

    if (!heap) {
        printf("Failed to allocate memory for Heap!");
        return NULL;
    }

    heap->maxSize = size;
    heap->size = 0;
    heap->data = (Word **) malloc(heap->maxSize * sizeof(Word *));

    if (!heap->data) {
        printf("Failed to allocate memory for Heap Array!");
        free(heap);
        return NULL;
    }

    for (int i = 0; i < heap->maxSize; i++) {
        heap->data[i] = (Word *) malloc(sizeof(Word));

        if (!heap->data[i]) {
            printf("Failed to allocate memory for Heap Array, index: %i", i);
        }
    }

    return heap;
}