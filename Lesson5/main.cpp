#include <iostream>

int main(){

//1.---------------------------------------------------------
    int Array[20] = {1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,1,0,0};
    int Array1[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    //for(int i = 0; i < 20; i++){
    //    Array[i] ^= 1;
    //    std::cout << Array[i];
    //}


    //int Array_task2[8] = {0};
    //for (int i = 0; i < 8; i++){
    //    Array_task2[i]
    //}



    Array[20] ^= Array1[20];
    for(int i = 0; i < 20; i ++){
        std::cout << Array[i];
    }
    return 0;
}
