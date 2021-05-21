#include "Utils/Utils.h"

int main() {

    /// Initializing the required variables
    WORD_COUNT = 0;

    WORDS = NULL;
    LINKED_LIST = NULL;
    BST = NULL;
    /// ----------

    /// Read data from file
    readDictionary("Dictionary.txt");

    traverseBinarySearchTree(BST);
    printf("\n");

    char word[30] = "break";

    printf("%s ", lookupBinarySearchTree(word));

    return 0;
}