#include <stdio.h>


int is_num_simple(int num){
    for(int i = 2;i < num;i++){
        if(num % i == 0){
            printf("Number is not simple\n");
            return 0;
        }
    }
    printf("Number is simple\n");
    return 0;
}

int main(){

    is_num_simple(15);
    is_num_simple(7);
    is_num_simple(14);

    
    return 0;
}
