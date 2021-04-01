#include <iostream>


bool is_brackets_rigth(char *CharArray, int length){
    char brackets_arr[] = "({[";
    char brackets_arr_closed[] = ")}]";

    for(int i = 0; i < length; i++){ 
        start:

        for(int brak = 0;brak < 3; brak++){
            if(brackets_arr[brak] == CharArray[i]){
               
                for(int j = i; j < length; j++){
                    if(CharArray[j] == brackets_arr_closed[brak]){
                        j = length;
                        i++;
                        goto start;
                    }
                }return false;
            } 
        }
    }
    return true;
}



int main(){

    char CharArray[] = "{2/{5*(4+7)]";
    char CharArray_right[] = "(2+(2*2))";
    int length, length_right;
    length = sizeof(CharArray)/sizeof(CharArray[0]);
    length_right = sizeof(CharArray_right)/sizeof(CharArray_right[0]);

    std::cout << "{2/{5*(4+7)]"<<is_brackets_rigth(CharArray, length) << std::endl;
    std::cout <<  "(2+(2*2))"<<is_brackets_rigth(CharArray_right, length_right);
}
