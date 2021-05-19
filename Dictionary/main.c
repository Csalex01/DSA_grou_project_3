#include <stdio.h>

#include "Utils/Utils.h"

int main() {
    Word* word = createWord("Table", "Asztal");

    printWord(word);

    destroyWord(word);

    return 0;
}
