//
// Created by Jakub Pajor on 12.03.2018.
//

#ifndef SYSOPS_STATCHARRAY_H
#define SYSOPS_STATCHARRAY_H


const int s_Charray_MAX_LENGTH = 10000;
const int s_Charray_MAX_BLOCK = 10000;

typedef struct s_Charray{
    int index_start;
    int index_stop;
    int block_sum;
    int block_length;
    char char_block[s_Charray_MAX_BLOCK];
}s_Charray[s_Charray_MAX_LENGTH];

void s_init_or_refresh(s_Charray array);
void s_create_char_array(s_Charray array, int array_length);
int s_sum_char_block(char * char_block);
void s_create_char_block(s_Charray array, int index, char * block_content);
void s_delete_char_block(s_Charray array, int index);
void s_change_char_block(s_Charray array, int index, char * new_block_content);
int s_closest_bsum_index(s_Charray array, int value);
void s_printCharray(s_Charray array);

#endif //SYSOPS_STATCHARRAY_H
