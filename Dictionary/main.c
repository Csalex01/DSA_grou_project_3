#include "Utils/Utils.h"

int main() {

    /// Initializing the required variables
    WORD_COUNT = 0;

    WORDS = NULL;
    LINKED_LIST = NULL;
    BST = NULL;
    HEAP = NULL;
    /// ----------

    /// Read data from file
    readDictionary("Dictionary200.txt");
    printWords();

    struct Heap* heap = createHeap(10);



    return 0;
}