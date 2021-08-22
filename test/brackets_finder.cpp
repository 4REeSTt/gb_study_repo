#include <stdio.h>


int is_brackets_rigth(char *CharArray, int length){
    char brackets_arr[] = "({[";
    char brackets_arr_closed[] = ")}]";
    int open_brac_flag = 0;

    //Check if every open bracket have closing one
    for(int i = 0; i < length; i++){ 
        start:
        for(int brak = 0;brak < 3; brak++){
            if(brackets_arr[brak] == CharArray[i]){
                open_brac_flag++;
                for(int j = i; j < length; j++){
                    if(CharArray[j] == brackets_arr_closed[brak]){
                        j = length;
                        i++;
                        goto start;
                    }
                }return 0;
            }
        }
    }
    //Check if there is no open bracets
    if(!open_brac_flag)
        for(int i = 0; i < 3; i++)
            for(int str = 0; str < length; str++)
                if(CharArray[str] == brackets_arr_closed[i])
                    return 0;
    return 1;
}



int main(){

    char CharArray[] = "{2/5*{(4+7)]";
    char CharArray_right[] = "(2+(2*2))";
    int length, length_right;
    length = sizeof(CharArray)/sizeof(CharArray[0]);
    length_right = sizeof(CharArray_right)/sizeof(CharArray_right[0]);

    printf("{2/{5*(4+7)]: %d\n", is_brackets_rigth(CharArray, length));
    printf("(2+(2*2)): %d\n", is_brackets_rigth(CharArray_right, length_right));
}
