#include <stdio.h>
#include <stdlib.h>

//1.---------------------------------------------------------------
int is_brackets_rigth(char *CharArray, int length){
    char brackets_arr[] = "({[";
    char brackets_arr_closed[] = ")}]";
    int open_brac_flag = 0;

    //Check if every open bracket have closing one
    for(int i = 0; i < length; i++){ 
        start:
        for(int brak = 0;brak < 3; brak++){
            if(brackets_arr[brak] == CharArray[i]){
                open_brac_flag++;
                for(int j = i; j < length; j++){
                    if(CharArray[j] == brackets_arr_closed[brak]){
                        j = length;
                        i++;
                        goto start;
                    }
                }return 0;
            }
        }
    }
    //Check if there is no open bracets
    if(!open_brac_flag)
        for(int i = 0; i < 3; i++)
            for(int str = 0; str < length; str++)
                if(CharArray[str] == brackets_arr_closed[i])
                    return 0;
    return 1;
}



//2.---------------------------------------------------------------


typedef struct Node{
    int data;
    struct Node* next;
}Node;

void copy_list(Node* head, Node* newNode){
    while(head->next != NULL){
        newNode->data = head->data;
        newNode->next = (Node*) malloc(sizeof(Node));
        newNode = newNode->next;
        head = head->next;
    } 
    newNode->data = head->data;
    newNode->next = NULL;
}

void print_list(Node* head){
    while(head->next != NULL){
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}

void make_list(Node* head){
    for(int i = 0; i = 5; i++){
        head->data = i;
        head->next = (Node*)malloc(sizeof(Node));
        head = head->next;
    }
}

int main(){

    char CharArray[] = "{2/5*{(4+7)]";
    char CharArray_right[] = "(2+(2*2))";
    int length, length_right;
    length = sizeof(CharArray)/sizeof(CharArray[0]);
    length_right = sizeof(CharArray_right)/sizeof(CharArray_right[0]);

    printf("{2/{5*(4+7)]: %d\n", is_brackets_rigth(CharArray, length));
    printf("(2+(2*2)): %d\n", is_brackets_rigth(CharArray_right, length_right));

//2.---------------------------------------------------------------
    Node* head = (Node*)malloc(sizeof(Node));
    Node* chain1 = (Node*)malloc(sizeof(Node));
    Node* chain2 = (Node*)malloc(sizeof(Node));
    Node* tail = (Node*)malloc(sizeof(Node));

    head->data = 15;
    chain1->data = 20;
    chain2->data = 21;
    tail->data =100;

    head->next = chain1;
    chain1->next = chain2;
    chain2->next = tail;
    tail->next = NULL;

    printf("DEBUG1\n");
    printf("Original list:\t");
    print_list(head);

    Node* other = (Node*)malloc(sizeof(Node));
    other->data = 0;
    other->next = NULL;

    printf("Copied list:  \t");
    copy_list(head, other);
    print_list(other);



return 0;
}
