#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quicksort(int* array, int length);
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


int true_bucket_sort(int* array, int length){
    int bucket_0_20[length];
    int bucket_0_60[length];
    int bucket_0_inf[length];
    for(int i=0; i < length; i++){
        bucket_0_inf[i] = -1;
        bucket_0_60[i]  = -1;
        bucket_0_20[i]  = -1;
    }

    for(int i=0; i < length; i++){
        if(array[i]%2 != 0) continue;

        if(array[i] <= 20)
            bucket_0_20[i] = array[i];
        if((array[i] > 20) && (array[i] <= 60))
            bucket_0_20[i] = array[i];
        if(array[i] > 60)
            bucket_0_20[i] = array[i];
    }
    //buckets sort
    quicksort(bucket_0_20, length);
    quicksort(bucket_0_60, length);
    quicksort(bucket_0_inf, length);

    //make array sorted with buckets
    for(int i=0; i < length; i++){
        if(array[i]%2 != 0) continue;
        
        for(int j=0; j < length; j++){
            while((array[i]%2 != 0) && (i < length))
                i++;
            if(bucket_0_20[j] == -1) continue;
            array[i] = bucket_0_20[j];
            i++;
        }
        for(int k=0; k < length; k++){
            while((array[i]%2 != 0) && (i < length))
                i++;
            if(bucket_0_60[k] == -1) continue;
            array[i] = bucket_0_20[k];
            i++;
        }
        for(int n=0; n < length; n++){
            while((array[i]%2 != 0) && (i < length))
                i++;
            if(bucket_0_inf[n] == -1) continue;
            array[i] = bucket_0_20[n];
            i++;
        }
    }
    return 0;
}
    



int quicksort(int * array, int length){
    int* buff = (int*)malloc (sizeof(int) * length);
    int middle;
    middle = length/2;
    int leftpointer = 0, rightpointer = middle;
    int i = 0;
      if(length > 1){
          quicksort(array,middle);
          quicksort(&array[middle],length - middle);
      }else
            return 0;

    while((leftpointer < middle) && (rightpointer < length)){
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

    int Arr[12] = {0,2,8,3,4,6,5,9,8,2,7,3};
    bucket_sort_evenNums(Arr,length);
    for(int i = 0; i < length; i++){
        printf("%d ",Arr[i]);
    }

    printf("\nTrue bucket sort:");
    int Arr3[12] = {0,2,8,3,4,6,5,9,8,2,7,3};
    int Arr2[12] = {15,29,303,1000,2,0,18,3,90,2,22,0};
    true_bucket_sort(Arr2,length);
    true_bucket_sort(Arr3,length);
    printf("\n");
    for(int i = 0; i < length; i++){
        printf("%d ",Arr3[i]);
    }
    printf("\n");
    for(int i = 0; i < length; i++){
        printf("%d ",Arr2[i]);
    }
    printf("\n");


    return 0;
}
