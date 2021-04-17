#pragma once
#include <iostream>
#include "task1_reqursive_xor.cpp"


//Обьявление функций
namespace Task5{
    int tofeel_array(int * Array_task2, int length_of_arr);
    bool checkBalance(int * Array, int length);
    int Array_sideslide(int * Array, int length,int n);

}

bool CheckBalance_update(int * Array, int length);

bool (*CheckBalance_update_pointer)(int * Array, int length) = CheckBalance_update;
int (*Array_sideslide_pointer)(int * Array, int length,int n) = Task5::Array_sideslide;
bool (*checkBalance_pointer)(int * Array, int length) = Task5::checkBalance;
int (*tofeel_array_pointer)(int * Array_task2, int length_of_arr) = Task5::tofeel_array;

int main(){

//1.---------------------------------------------------------
    int Array[10] = {0,0,1,1,0,0,1,1,0,0};
    int length_task1_5;
    length_task1_5 = sizeof(Array)/sizeof(Array[0]);
    //for(int i = 0; i < 20; i++){
    //    Array[i] ^= 1;
    //}
//two types of XORing the array. 
    std::cout << "\nBefore XORing: ";
    for(int i = 0; i < length_task1_5; i ++){
        std::cout << Array[i] ;
    }
    Task5::rqur(Array, length_task1_5);
    
    std::cout << "\n\nAfter XORing:  ";
    for(int i = 0; i < length_task1_5; i ++){
        std::cout << Array[i] ;
    }
//----------------------------------------------------------


//2.-------------------------------------------------------- 
    int Array_task2[8] = {0};
    int length_of_arr = sizeof(Array_task2)/sizeof(Array_task2[0]);
    tofeel_array_pointer(Array_task2, length_of_arr); 
//----------------------------------------------------------


//3.--------------------------------------------------------
    int Array_for_balance[] = {10,1,2,3,4};
    int length_balance = sizeof(Array_for_balance)/sizeof(Array_for_balance[0]);
    
    std::cout << "\n\nBalence is working {10,1,2,3,4} :" << checkBalance_pointer(Array_for_balance, length_balance);

    std::cout << "\n\nNew balance function {10,1,2,3,4} :" << CheckBalance_update_pointer(Array_for_balance, length_balance) << "\n\n";
//----------------------------------------------------------

    const int length_float_array = 100;
    int FloatArray[length_float_array];
    for ( int i = 0;i < length_float_array; i++){
        FloatArray[i] = i;
    }
    int n;
    std::cout << "Enter n to slide array\n> ";
    std::cin >> n;
    Array_sideslide_pointer(FloatArray, length_float_array, n);

    

//5.
    std::cout << "\n\nNew XOR reqursive function. Accepts any number of arguments\n";
    rqur_new(1,1,1,1,0,0,0,0,0);

    return 0;
}
