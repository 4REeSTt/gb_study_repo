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


    float P[length] = {0}; 
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
        if(sqrt(fabs(P[i])) + 5 *pow(P[i], 3) > 400)
            printf("Your number %f more then 400\n", P[i]); 
    } 
    return 0;
}

int main(){
    int arr[10] = {5,3,1,3,5,6,8,5,3,12};
    bubble_sort(arr,10);
    for(int i = 0;i < 10;i++){
        printf("%d ",arr[i]);
    }

    TPK();
    return 0;
}
