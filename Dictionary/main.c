#include <stdio.h>

#include "Utils/Utils.h"

int main() {
    WORD_COUNT = 0;

    readDictionary("Dictionary.txt");

    printf("%i\n", WORD_COUNT);

    for (int i = 0; i < WORD_COUNT; i++)
        printWord(WORDS[i]);

    return 0;
}
