#include <stdio.h>
#include <math.h>

//Алгоритм сортирует только числа в диапозоне 0 - 99
int bucket_sort_evenNums(int * array,int length){
    int bucket[100] = {0};
    for(int i = 0; i < length; i++){
        if(array[i] % 2 == 0){
            bucket[array[i]]++;
            array[i] = -1;
        }
    } 
    for(int i = 0; i < length; i++){
        if(array[i] == -1){

            for(int j = 0; j < 100; j++){
                if(bucket[j] > 0){
                    bucket[j]--;
                    array[i] = j;
                    printf("array[%d] = %d \n",i,j);
                    break;
                }
            }
        }
    }
    return 0;
}






int quicksort(int * array, int length){
    int buff[length] = {0};
    int middle;
    middle = length/2;
    int leftpointer = 0, rightpointer = middle;
    int i = 0;
      if(length > 1){
          quicksort(array,middle);
          quicksort(&array[middle],length - middle);
      }else
            return 0;

    while((leftpointer < middle) and (rightpointer < length)){
        if(array[leftpointer] < array[rightpointer]){
            buff[i] = array[leftpointer];
            leftpointer++;
            i++;
        }else{
            buff[i] = array[rightpointer];
            rightpointer++;
            i++;
        }
    }
    
    if(leftpointer == middle){
        for(int j = rightpointer; j < length;j++){
            buff[i] = array[j];
            i++;
        }
    }else{
        for(int j = leftpointer; j < middle; j++){
            buff[i] = array[j];
            i++;
        }
    }
    for(int j = 0; j < length;j++){
        array[j] = buff[j];
    }
    return 0;
}

int main(){

    int length = 12;
    int Array[length];
    for(int i = 0; i < length; i++){
        Array[i] = rand()%1000000;
    }
    printf("Array to sort::\n");
    for(int i = 0; i < length; i++){
        printf("%d ",Array[i]);
    }
    quicksort(Array,length);
    printf("\n\n");
    for(int i = 0; i < length; i++){
        printf("%d ",Array[i]);
    }
    printf("\nsorted\n\n");



    int Arr[length] = {0,2,8,3,4,6,5,9,8,2,7,3};
    bucket_sort_evenNums(Arr,length);
    for(int i = 0; i < length; i++){
        printf("%d ",Arr[i]);
    }
    return 0;
}