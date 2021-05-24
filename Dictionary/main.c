#include "Utils/Utils.h"
#include "Menu/Menu.h"

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

    activateMenu();

    return 0;
}