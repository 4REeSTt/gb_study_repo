#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 50
#define STACK_EMPTY (-1)




int Stack[STACK_SIZE];
int top = -1;

bool push(int value){
    if(top >= STACK_SIZE) 
        return 0;
    top++;
    Stack[top] = value;
    return 1;
}

int pop(){
    if(top <= -1)
        return STACK_EMPTY;

    int result = Stack[top];
    top--;
    return result;
}

void tobin(int integer){
    while(integer > 0){
        push(integer % 2);
        integer /= 2;
    }
    int t;
    while((t = pop()) != STACK_EMPTY){
        printf("%d",t);
    } 
    printf("\n");

}


int main(){

    printf("number 5 in binary: ");
    tobin(5);
    printf("number 505 in binary: ");
    tobin(505);
}
