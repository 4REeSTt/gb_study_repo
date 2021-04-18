#include <iostream>
//1.-----------------------------------------------------------------------------------------------------
#define CHECK_DIAPOSON(number,folow_num) ((number >= 0)&&(number < folow_num))?true:false
//2.-----------------------------------------------------------------------------------------------------
#define ARRAY_ELEMENT(i,j) Arr_dinamic[i*M+j]
//3.-----------------------------------------------------------------------------------------------------
#define ARR_SIZE(index,type) sizeof(index)/sizeof(type)


int main(){
    
    //1.
    std::cout << (CHECK_DIAPOSON(5,10)) << std::endl;

    //2.
    int * Arr_dinamic,
        N = 5,
        M = 5;

    Arr_dinamic = new int [M*N];
    Arr_dinamic[19] = 33;
    std::cout << ARRAY_ELEMENT(3,4) << '\n';

    delete[] Arr_dinamic;

    //3.
    int Array[10] = {0};
    std::cout << ARR_SIZE(Array,int);
    return 0;
}
