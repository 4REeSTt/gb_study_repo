#include <stdio.h>

int binary;
int to_binary(int num){
    if(num == 1){

    }
    return 0;
}



int powering_num(int num,int power){
    if(power == 1){ 
        return num;
    }
    power --;
    num *= powering_num(num,power);
    return num;
}

int powering_num_advanced(int num,int power){
    while(power % 2 == 0){
        num *= num;
        power /= 2;
    }
    if(power == 1){ 
        return num;
    }
    
    power--;
    num *= powering_num_advanced(num,power);
    return num;
}


int main(){
    int a = powering_num_advanced(5,7);
    printf("%d\n",a);
    return 0;
}
