//
// Created by Jakub Pajor on 11.03.2018.
//
#include "charray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* generateRandomString(int maxSize){
    if (maxSize < 1) return NULL;
    char *base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    size_t baseLength = strlen(base);
    char *newString = (char *) malloc((maxSize) * sizeof(char));
    int newStringLength = maxSize - (rand() % maxSize);

    for (int i = 0; i < newStringLength; ++i) {
        newString[i] = base[rand()%baseLength];
    }
    for (int i = newStringLength; i < maxSize + 1; i++){
        newString[i] = '\0';
    }
    return newString;
}

int main() {
    srand(time(NULL));
    int is_static = 1;
    int elements = 120;
    Charray * charray = create_char_array(NULL,elements,is_static);

    for(int i = 0; i < 20; i++){
        create_char_block(charray,i,generateRandomString(10),is_static);
    }

    delete_char_block(charray,3,is_static);

    change_char_block(charray,70,"zmiana bloku",is_static);

    //charray = resize_char_array(charray,2000,is_static);
    //create_char_block(charray,19,a9,is_static);
    //delete_char_array(charray,is_static);
    printCharray(charray);




    return 0;
}