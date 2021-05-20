#include "Utils/Utils.h"

int main() {

    /// Initializing the required variables
    WORD_COUNT = 0;

    LINKED_LIST = NULL;

    /// ----------

    /// Read data from file
    readDictionary("Dictionary.txt");

    traverseLinkedList(LINKED_LIST);

    return 0;
}

