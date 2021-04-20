#include <stdio.h>

//1.------------------------------------------------------
int binary;
int to_binary(int num){
    if(num == 1){
        printf("%d", num);
        return 0;
    }

    to_binary(num/2);
    printf("%d",num % 2);
    return 0;
}

//2.a.---------------------------------------------------
int powering_num(int num,int power){
    if(power == 1){ 
        return num;
    }
    power --;
    num *= powering_num(num,power);
    return num;
}
//2.b.---------------------------------------------------
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

//3.



int main(){

    //1.
    int number_to_convert = 20;
    printf("Your nubmer %d in binary is: ", number_to_convert);
    to_binary(number_to_convert);

    //2.
    int a = powering_num(5,7); 
    printf("\n\nPowering number 5 at 7th exponent(slow way) is: %d",a);
    int b = powering_num_advanced(5,7);
    printf("\n\nPowering number 5 at 7th exponent is: %d\n",b);

    
    //3.
    




    return 0;
}
