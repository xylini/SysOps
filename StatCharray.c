//
// Created by Jakub Pajor on 12.03.2018.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "StatCharray.h"

void s_init_or_refresh(s_Charray array){
    for(int i = 0; i < s_Charray_MAX_LENGTH; i++){
        array[i].char_block[0] = '/0';
        array[i].block_length = NULL;
        array[i].block_sum = NULL;
        array[i].index_start = NULL;
        array[i].index_stop = NULL;
    }
}

void s_create_char_array(s_Charray array, int array_length){
    int index_start = 0;
    int index_stop = array_length-1;

    while(array[index_start].index_stop != NULL && index_start < s_Charray_MAX_LENGTH && index_stop < s_Charray_MAX_LENGTH){
        index_start = array[index_start].index_stop+1;
        index_stop = index_start + array_length-1;
    }

    if(index_stop >= s_Charray_MAX_LENGTH || index_start >= s_Charray_MAX_LENGTH){
        fprintf(stderr,"s_create_char_array: Not enought memory in array. Init new s_Charray.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = index_start; i <= index_stop; i++){
        array[i].index_start = index_start;
        array[i].index_stop = index_stop;
    }
}

int s_sum_char_block(char * char_block){
    int i = 0;
    int block_sum=0;
    while(char_block[i] != '\0'){
        block_sum += char_block[i];
        i++;
    }
    return block_sum;
}

void s_create_char_block(s_Charray array, int index, char * block_content){
    if(index >= s_Charray_MAX_LENGTH || index < 0){
        fprintf(stderr,"s_create_char_block: The index is out of range. Available range: %d to %d.\n",0,s_Charray_MAX_LENGTH);
        exit(EXIT_FAILURE);
    }
    if(array[index].block_length != NULL){
        fprintf(stderr,"s_create_char_block: The block is already is usage.");
        exit(EXIT_FAILURE);
    }

    int block_length = strlen(block_content);

    if(block_length >= s_Charray_MAX_BLOCK){
        fprintf(stderr,"s_create_char_block: Given char * block is to large. Max size: %d.\n",s_Charray_MAX_BLOCK-1);
        exit(EXIT_FAILURE);
    }
    strcpy(array[index].char_block,block_content);
    array[index].char_block[block_length] = '\0';
    array[index].block_length = block_length;
    array[index].block_sum = s_sum_char_block(array[index].char_block);
}

void s_delete_char_block(s_Charray array, int index){
    if(index >= s_Charray_MAX_LENGTH || index < 0){
        fprintf(stderr,"s_delete_char_block: The index is out of range. Available range: %d to %d.\n",0,s_Charray_MAX_LENGTH);
        exit(EXIT_FAILURE);
    }
    array[index].char_block[0] = '/0';
    array[index].block_length = NULL;
    array[index].block_sum = NULL;

}

void s_change_char_block(s_Charray array, int index, char * new_block_content){
    if(index >= s_Charray_MAX_LENGTH || index < 0){
        fprintf(stderr,"s_change_char_block: The index is out of range. Available range: %d to %d.\n",0,s_Charray_MAX_LENGTH);
        exit(EXIT_FAILURE);
    }
    int block_length = strlen(new_block_content);

    if(block_length >= s_Charray_MAX_BLOCK){
        fprintf(stderr,"s_change_char_block: Given char * block is to large. Max size: %d.\n",s_Charray_MAX_BLOCK-1);
        exit(EXIT_FAILURE);
    }
    strcpy(array[index].char_block,new_block_content);
    array[index].char_block[block_length] = '\0';
    array[index].block_length = block_length;
    array[index].block_sum = s_sum_char_block(array[index].char_block);
}

int s_closest_bsum_index(s_Charray array, int value){
    int index = 0;
    int difference = INT_MAX;
    int abs_diff;
    for(int i = 0; i < s_Charray_MAX_LENGTH && array[i].index_start != NULL; i++){
        abs_diff = abs(value - array[i].block_sum);
        if(abs_diff < difference){
            difference = abs_diff;
            index = i;
        }
    }

    return index;
}
void s_printCharray(s_Charray array){
    for(int i = 0; i < s_Charray_MAX_LENGTH && array[i].index_start != NULL; i++){
        printf("%s\n",array[i]);
    }
}

