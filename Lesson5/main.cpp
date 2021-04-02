#include <iostream>

//1.---
int rqur(int * Array, int length){
     if(length > -1){
         Array[length] ^= 1;
         rqur(Array, length - 1);
     }else{ return 0;}
     return 0;
}


//3.---
//Функцию можно оптимизировать, если сделать расчет от центра и в зависимости от разности сторон двигаться в сторону с
//меньшей суммой. center_sum_pointer = length/2; не получается адекватно реализовать пока что, воможно позже вернусь,
//упираюсь в зацикливаемость, либо слишком большое количество условных операторов выходит. Работать в таком случае
//функция будет гараздо быстрее

bool checkBalance(int * Array, int length){
    int leftside = 0,rightside = 0, center_sum_pointer;
    center_sum_pointer = 1; 

    while(center_sum_pointer < length){
        for(int i = 0; i < center_sum_pointer;i++){
            leftside += Array[i];
        }for (int j = center_sum_pointer;j < length; j++){
            rightside += Array[j];
        }
        
        if( leftside == rightside){
            return true;
        }
        leftside = 0; rightside = 0;
        center_sum_pointer++;
    }
    return false;
}


//4.---
int Array_sideslide(int * Array, int length,int n){
    int tmp1, tmp2;
    if(n < 0){

        while (n != 0){
            for(int i = length - 1; i > 0; i--){
                if (i == length){
                }
                tmp1 = Array[i];
                tmp2 = Array[i - 1];
                Array[i - 1] = tmp1;
                tmp1 = tmp2
            }      
        }
    }else{

        while(n != 0){
        }
    }

    for(int i = 0; i < length; i++){}
    return 0;
}    









int main(){

//1.---------------------------------------------------------
    int Array[20] = {1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,1,0,0};
    //for(int i = 0; i < 20; i++){
    //    Array[i] ^= 1;
    //}
//two types if XORing the array. 
    std::cout << "\nBefore XORing: ";
    for(int i = 0; i < 20; i ++){
        std::cout << Array[i] ;
    }
    rqur(Array, 20);
    
    std::cout << "\n\nAfter XORing:  ";
    for(int i = 0; i < 20; i ++){
        std::cout << Array[i] ;
    }
//----------------------------------------------------------


//2.-------------------------------------------------------- 
    int Array_task2[8] = {0};
    for (int i = 0; i < 8; i++){
        if (i == 0){
            Array_task2[i] = 1;
            continue;
        }
        Array_task2[i] = Array_task2[i - 1] + 3;
    }

    std::cout << "\n\nArray is: ";
    for(int i = 0;i < 8;i++){
        std::cout << Array_task2[i] << " ";
    }
//----------------------------------------------------------


//3.--------------------------------------------------------
    int Array_for_balance[] = {10,1,2,3,4};
    int length_balance = sizeof(Array_for_balance)/sizeof(Array_for_balance[0]);
    
    std::cout << "\n\nBalence is working {10,1,2,3,4} :" << checkBalance(Array_for_balance, length_balance) << "\n";
//----------------------------------------------------------

    const int length_float_array = 100;
    int FloatArray[length_float_array];
    for ( int i = 0;i < length_float_array; i++){
        FloatArray[i] = i;
    }
    int n;
    std::cout << "Enter n to slide array";
    std::cin >> n;
    Array_sideslide(FloatArray, length_float_array, n);

    













    
    return 0;
}
