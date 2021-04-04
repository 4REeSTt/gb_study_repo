#include <iostream>
//1.-----------------------------------------------------------------------------------------------------
#define check_diaposon(number,folow_num) ((number >= 0)&&(number < folow_num))?true:false
//-------------------------------------------------------------------------------------------------------
//3.-----------------------------------------------------------------------------------------------------
#define ARR_SIZE(index,type) sizeof(index)/sizeof(type)



int main(){
    std::cout << (check_diaposon(5,10)) << std::endl;

    int Array[10] = {0};
    std::cout << ARR_SIZE(Array,int);
    return 0;
}
