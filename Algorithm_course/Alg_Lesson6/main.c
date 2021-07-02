#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 50
#define STACK_EMPTY (-1)


typedef struct{
    int prior;
    int data;
}Node;

Node* arr[STACK_SIZE];
int max_prior = 0;

void init(){
    for(int i = 0; i < STACK_SIZE; i++){
        arr[i] = NULL;
    }
}

int position = 0;
int add_queue(Node* arr, Node node){
    if(position = STACK_SIZE){
        printf("queue is full");
        return -1;
    }
    arr[position]  = node;
    position++;
    if(max_prior < node.prior)
        max_prior = node.prior;
}

int find_next_prior(Node* arr){
    int tmp = 0;
    for(int i = 0; i < STACK_SIZE; i++)
        if(arr[i].prior > tmp)
            tmp = arr[i].prior;
    max_prior = tmp;
} 
int pop_queue(Node* arr){
    if(!position){
        printf("queue is empty");
        return -1;
    }
    for(int i = 0; i < STACK_SIZE; i++){
        if(arr[i].prior == max_prior){
            arr[i] = NULL;
        }
        find_next_prior(arr);
        position--;
    }
}

//2.--------------------------------------------------------------------
int Stack[STACK_SIZE];
int top = -1;

//stack logic
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

//to bin finc--------------------------------------------------
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
