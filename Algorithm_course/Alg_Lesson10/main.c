#include <stdio.h>
#include <stdlib.h>

//1.---------------------------------------------------
unsigned int hash(char* str) {
    unsigned int c = 0;
    while (*str != '\0') {
        c += *str;
        str++;
    }
    return c;
}
//2.---------------------------------------------------
int coins[5] = {50, 10, 5, 2, 1};

int* find_optimal_conins(int price){
    int* coin_counter = (int*)calloc(0,sizeof(int)*5);
    for(int i = 0; i < 5; i++){
        if(price <= 0) break;
        while(price / coins[i] >= 1){
            coin_counter[i]++;
            price -= coins[i];
        }
    }
    return coin_counter;
}

int main(){

//1.---------------------------------------------------
    printf("\nString 'hello world' = %d\n\n", hash("hello world"));

//2.---------------------------------------------------
    int * final = find_optimal_conins(98);

    printf("For 98 price we took coins:\n");
    for(int i = 0; i < 5; i++)
        printf("%d: %d\n", coins[i], final[i]);

    return 0;
}
