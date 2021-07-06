#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 50
#define STACK_EMPTY (-1)


typedef struct Node{
    int data;
    int prior;
}Node;

int counter = -1;
int max_prior = 0;


int find_next_prior(Node** arr){
    if(counter == -1){
        printf("array is empty");
        return 0;
    }
    max_prior = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] != NULL){
            if(arr[i]->prior > max_prior){
                max_prior = arr[i]->prior;            
            }
        }
    }
}

int add_item(Node** arr, Node* node){
    if(counter == 9){
        printf("array is full");
        return 0;
    }
    counter++;
    for(int i = 0; i < 10; i++){
        if(arr[i] == NULL){
            arr[i] = node;
            max_prior = arr[counter]->prior;
            find_next_prior(arr);
            return 1;
        }
    }
}

int rm_item(Node** arr){
    if(counter == -1){
        printf("array is empty");
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(arr[i] == NULL)
            continue;
        if(arr[i]->prior == max_prior){
            arr[i] = NULL;
            counter--;
            find_next_prior(arr);
            return 1;
        }
    } 
}

void print_arr(Node** arr){
    for(int i = 0; i < 10; i++){
        if(arr[i] == NULL){
            printf("[],");
            continue;
        }
        printf("[%d, %d],", arr[i]->prior, arr[i]->data);
    }
    printf("\n");
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
	
	printf("\n");
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    
    node1->data = 15;
    node1->prior = 3;
    node2->data = 20;
    node3->data = 30;
    node2->prior = 1;
    node3->prior = 10;


    Node* arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = NULL;
    }

    add_item(arr, node3);
    add_item(arr, node1);
    add_item(arr, node2);
    add_item(arr, node1);
    add_item(arr, node3);

    print_arr(arr);

    printf("rm one item\n");
    rm_item(arr);
    print_arr(arr);

    printf("rm one item\n");
    rm_item(arr);
    print_arr(arr);


    printf("add three items\n");
    add_item(arr, node3);
    add_item(arr, node2);
    add_item(arr, node1);

    print_arr(arr);
    printf("\n");

//2.------------------------------------------------------------
    printf("number 5 in binary: ");
    tobin(5);
    printf("number 505 in binary: ");
    tobin(505);
	
}
