#include "../Utils/Utils.h"

struct Heap *createHeap(int size) {
    struct Heap *heap = (struct Heap *) malloc(sizeof(struct Heap *));

    if (!heap) {
        printf("Failed to allocate memory for Heap!");
        return NULL;
    }

    heap->maxSize = size;
    heap->size = -1;
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

Word *deleteMaxFromHeap() {
    Word *tmp = HEAP->data[0];
    HEAP->data[0] = HEAP->data[HEAP->size];
    HEAP->data[HEAP->size] = tmp;

    HEAP->size--;

    return tmp;
}

void insertIntoHeap(Word *word) {
    if (HEAP->size >= HEAP->maxSize) {
        printf("Could not insert into Heap!");
        return;
    }

    HEAP->size++;

    HEAP->data[HEAP->size] = word;

    up(HEAP->size);
}

void up(int i) {
    while (i > 0 &&
           stringToInt(HEAP->data[i / 2]->ENG) <
           stringToInt(HEAP->data[i]->ENG)) {

        Word *tmp = HEAP->data[i / 2];
        HEAP->data[i / 2] = HEAP->data[i];
        HEAP->data[i] = tmp;

        i /= 2;
    }
}

void down(int i) {
    while (2 * i < HEAP->size) {
        int j = 2 * i;

        if (j < HEAP->size &&
            stringToInt(HEAP->data[j]->ENG) <
            stringToInt(HEAP->data[j + 1]->ENG))

            i++;

        if (stringToInt(HEAP->data[j]->ENG) < stringToInt(HEAP->data[j]->ENG))
            break;

        Word *tmp = HEAP->data[i];
        HEAP->data[i] = HEAP->data[j];
        HEAP->data[j] = tmp;

        i = j;
    }
}

void heapSort() {
    for (int i = HEAP->size / 2 - 1; i >= 0; i--)
        down(i);

//    for(int i = 0; i < HEAP->size; i++) {
//        deleteMaxFromHeap();
//        down(1);
//    }
}

void printHeap() {
    for (int i = 0; i <= HEAP->size; i++)
        printWord(HEAP->data[i]);
}