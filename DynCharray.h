//
// Created by Jakub Pajor on 08.03.2018.
//

#ifndef SYSOPY1_DYNCHARRAY_H

typedef struct Charray{
    int length;
    int block_length;
    int block_sum;
    char * char_block;
}Charray;

Charray * create_char_array(Charray * array, int array_length);
Charray * resize_char_array(Charray * array, int new_array_length);
Charray * delete_char_array(Charray * array);
int sum_char_block(char * char_block);
Charray * create_char_block(Charray * array, int index, char * block_content);
Charray * delete_char_block(Charray * array, int index);
Charray * change_char_block(Charray * array, int index, char * new_block_content);
int closest_bsum_index(Charray * array, int value);
void printCharray(Charray * array);


#define SYSOPY1_DYNCHARRAY_H

#endif //SYSOPY1_DYNCHARRAY_H
