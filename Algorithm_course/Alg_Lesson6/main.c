#include <stdio.h>

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




int main(){
    push(56);
    push(78);
    push(13);

    int t;
    while((t = pop()) != STACK_EMPTY){
        printf("%d ",t);
    }
}
