#include <stdio.h>
#include <math.h>


void bubble_sort(int * Arr,int length){
    int tmp ;
    while(length > 1){
        for(int i = 0;i < length;i++){
            if(Arr[i] > Arr[i + 1]){
                tmp = Arr[i];
                Arr[i] = Arr[i + 1];
                Arr[i + 1] = tmp;
            } 
        }
        length--;
    }
}

int TPK(){
    printf("\nEnter 11 numbers\n");
    int length = 11;
    int tmp;


    float P[11] = {0}; 
    for(int i = 0; i < length;i++){
        printf("\nEnter number  [%d]\n>>>  ", i + 1);
        scanf("%f",&P[i]);
    }

//Inverting Array 
    for(int i = 0; i < length/2; i++){
        tmp = P[i];
        P[i] = P[length - i - 1];
        P[length - i - 1] = tmp; 
    }
    
    for(int i = 0;i < length;i++){
        float y = (sqrt(fabs(P[i])) + 5.0 *pow(P[i], 3.0));
        if(y < 400){
            printf("Your number %f less then 400. Changed is %f\n", P[i], y); 
        }
    } 
    return 0;
}

int main(){
    int length = 20;
    int arr[length]; 

//Creating random array
    for (int i = 0;i < length; i++){
        arr[i] = rand()%100000;
    }
    printf("Not sorted array\n");
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }

    bubble_sort(arr,length);
    printf("\n");

    printf("Sorted one\n");
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }

    TPK();
    return 0;
}
