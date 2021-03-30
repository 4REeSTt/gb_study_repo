#include <iostream>


int bubble_sort(int * Array, int length){
    while(length > 2){
        for(int i = 0; i < length - 1; i++){
            if(Array[i] > Array[i + 1]){
                int tmp;
             tmp = Array[i];
             Array[i] = Array[i + 1];
             Array[i + 1] = tmp;
            }
        }
        length -= 1;
    }
    std::cout << "Array is sorted" << std::endl;
    return 0;
}

int choise_sort(int  * Array, int length){ 
     int tmp;
     for(int i = 0; i < length - 1;i++){
        for(int j = i + 1; j < length; j++){
            if(Array[i] > Array[j]){
                tmp = Array[j];
                Array[j] = Array[i];
                Array[i] = tmp;
            }
        }
     }
    std::cout << "Array is sorted" << std::endl;
    return 0;
}

int insert_sort(int * Array,int length){

    return 0;
}

//Создаем массив который считает количесво вхождений числа в основном массиве
int count_sort(int * Array,int length){
    int placeholder = 0;
    int count_i = 0;
    int Array_counter[10] = {0};
    for(int i = 0; i < length; i++){
        Array_counter[Array[i]] += 1;
    }

//Затем переписывает его i это число Ar[i] количество вхождений
    for(int i = 0; i < 10; i++){
        while(Array_counter[i] != 0){
            Array[placeholder] = i;
            placeholder += 1;
            Array_counter[i] -= 1;
        }
    }
    return 0;
}




int main(){
    int Array[10] = {5,3,2,1,5,3,6,7,3,10};
    int length = 10;

//    bubble_sort(Array, length);
//    choise_sort(Array, length);
//    count_sort(Array, length);


    for(int i = 0; i < length; i++){
        std::cout << Array[i] << " ";
    }
    return 0;
}
