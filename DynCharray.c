//
// Created by Jakub Pajor on 08.03.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "DynCharray.h"
Charray * create_char_array(Charray * array, int array_length){
    if(array != NULL) {
        fprintf(stderr,"create_char_array: The array is already allocated with length %d or is not NULL when trying to create array.\n",array[0].length);
        exit(EXIT_FAILURE);
    }

    array = calloc(array_length, sizeof(Charray));
    if(array == NULL) {
        fprintf(stderr,"create_char_array: No memory available\n");
        exit(EXIT_FAILURE);
    }
    array[0].length = array_length;
    for (int i = 0; i < array_length; i++) {
        array[i].block_length = 0;
        array[i].block_sum = NULL;
        array[i].char_block = NULL;
    }
    return array;
}


Charray * resize_char_array(Charray * array, int new_array_length){
    Charray * newArray = realloc(array,(array[0].length + new_array_length) * sizeof(Charray));

    if(newArray == NULL){
        fprintf(stderr,"resize_char_array: No memory available.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = array[0].length-1; i < new_array_length; i++){
        array[i].block_length = 0;
        array[i].char_block = NULL;
    }
    newArray[0].length = new_array_length;
    return newArray;
}

Charray * delete_char_array(Charray * array){
    if(array == NULL){
        fprintf(stderr,"delete_char_array: Given pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < array[0].length; i++){
        //array = delete_char_block(array,i);
    }
    array[0].length = 0;
    free(array);
    array = NULL;
    return array;
}


int sum_char_block(char * char_block){
    int i = 0;
    int block_sum=0;
    while(char_block[i] != '\0'){
        block_sum += char_block[i];
        i++;
    }
    return block_sum;
}

Charray * create_char_block(Charray * array, int index, char * block_content){
    if (array == NULL){
        fprintf(stderr,"create_char_block: Given array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if (index >= array[0].length){
        fprintf(stderr,"create_char_block: Given index in Charray * is beyond the range. Use reallocate_char_array function.\n");
        exit(EXIT_FAILURE);
    }
    if(array[index].char_block != NULL){
        fprintf(stderr,"create_char_block: Charray * was allocated inappropriately or given block index is already allocated(!= NULL)."
                "\n\t Use create_char_array or change_char_array function.\n");
        exit(EXIT_FAILURE);
    }
    if(array[index].block_length != 0){
        fprintf(stderr,"create_char_block: Charray * is already allocated.\n");
        exit(EXIT_FAILURE);
    }

    int block_length = strlen(block_content);
    array[index].char_block = calloc(block_length + 1, sizeof(char));
    strcpy(array[index].char_block,block_content);
    array[index].char_block[block_length] = '\0';
    array[index].block_length = block_length;
    array[index].block_sum = sum_char_block(array[index].char_block);
    return array;
}

Charray * delete_char_block(Charray * array, int index){
    if(array == NULL){
        fprintf(stderr,"delete_char_block: Given array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(index >= array[0].length){
        fprintf(stderr,"delete_char_block: Given index does not point to allocated block.\n");
        exit(EXIT_FAILURE);
    }
    if(array[index].char_block == NULL){
        fprintf(stderr,"delete_char_block: Given block index is NULL or has been freed.\n");
        exit(EXIT_FAILURE);
    }

    array[index].block_length = 0;
    free(array[index].char_block);
    array[index].char_block = NULL;
    array[index].block_sum = NULL;
    return array;

}

Charray * change_char_block(Charray * array, int index, char * new_block_content){
    array = delete_char_block(array,index);
    array = create_char_block(array,index,new_block_content);
    return array;

}

int closest_bsum_index(Charray * array, int value){
    int index = 0;
    int difference = INT_MAX;
    int abs_diff;
    for(int i = 0; i < array[0].length; i++){
        abs_diff = abs(value - array[i].block_sum);
        if(abs_diff < difference){
            difference = abs_diff;
            index = i;
        }
    }

    return index;
}

void printCharray(Charray * array){
    for(int i = 0; i < array[0].length; i++){
        printf("%s",array[i].char_block);
        printf("\n");
    }
}

