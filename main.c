//
// Created by Jakub Pajor on 11.03.2018.
//
#include "DynCharray.h"
#include <stdio.h>

int main() {
    char * a0 = "000000000000000";
    char * a1 = "111111111111111";
    char * a2 = "222222222222222";
    char * a3 = "333333333333333";
    char * a4 = "444444444444444";
    char * a5 = "555555555555555";
    char * a6 = "666666666666666";
    char * a7 = "777777777777777";
    char * a8 = "888888888888888";
    char * a9 = "999999999999999";


    Charray * charray = NULL;
    charray = create_char_array(charray,10);
    create_char_block(charray,0,a0);
    create_char_block(charray,1,a1);
    create_char_block(charray,2,a2);
    create_char_block(charray,3,a3);
    create_char_block(charray,4,a4);
    create_char_block(charray,5,a5);
    create_char_block(charray,6,a6);
    create_char_block(charray,7,a7);
    create_char_block(charray,8,a8);
    create_char_block(charray,9,a9);

    delete_char_block(charray,3);

    change_char_block(charray,2,a9);


    char * ax = "33333333333333";
    int best_index = closest_bsum_index(charray,sum_char_block(ax));

    printf("%d\n",best_index);
    printCharray(charray);




    return 0;
}