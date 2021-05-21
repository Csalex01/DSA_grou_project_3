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

    Word* word = createWord("Break", "Tor");

    traverseBinarySearchTree(BST);
    printf("\n");

    deleteFromBinarySearchTree(BST, word);

    traverseBinarySearchTree(BST);

    return 0;
}