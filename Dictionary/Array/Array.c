#include "../Utils/Utils.h"

void insertIntoArray(Word* word, int index) {
    if(index < 0 || index >= WORD_COUNT)
        return;

    ARRAY[index] = word;
}

void deleteFromArray(int index) {
    if(WORD_COUNT <= 0)
        return;

    destroyWord(ARRAY[index]);
    WORD_COUNT--;

    for(int i = index; i < WORD_COUNT; i++) {
        ARRAY[i] = ARRAY[i + 1];
    }
}

char* lookupArrayENG(char* HUN) {
    for(int i = 0; i < WORD_COUNT; i++)
        if(!strcmp(ARRAY[i]->HUN, HUN))
            return ARRAY[i]->ENG;

    return NULL;
}

char* lookupArrayHUN(char* ENG) {
    for(int i = 0; i < WORD_COUNT; i++)
        if(!strcmp(ARRAY[i]->ENG, ENG))
            return ARRAY[i]->HUN;

    return NULL;
}

char* lookupArray(char* word) {
    fixString(word);

    char* ENG = lookupArrayHUN(word);
    char* HUN = lookupArrayENG(word);

    if(ENG)
        return ENG;

    if(HUN)
        return HUN;

    return NULL;
}

void fixString(char* string) {
    if(string[0] >= 'a' && string[0] <= 'z')
        string[0] = (char)(string[0] - 32);


    for(int i = 1; i < strlen(string); i++) {
        if(string[i] >= 'A' && string[i] <= 'Z')
            string[i] = (char)(string[i] + 32);
    }
}