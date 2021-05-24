#include "Utils/Utils.h"

int main() {

    /// Initializing the required variables
    WORD_COUNT = 0;

    ARRAY = NULL;
    HASH_TABLE = NULL;
    LINKED_LIST = NULL;
    BST = NULL;
    HEAP = NULL;
    /// ----------

    /// Read data from file
    readDictionary("Dictionary300.txt");

    printf("---------------\nWord count: %i\n---------------\n", WORD_COUNT);

    printHeap();
    printf("\n");

    heapSort();

    printHeap();

    return 0;
}