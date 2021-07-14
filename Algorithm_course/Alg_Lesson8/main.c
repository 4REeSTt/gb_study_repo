#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* Lefl_node;
    struct Node* Right_node;
}Node;

//1.------------------------------------------------------------------
int max(int a, int b);

int height(Node* root){
    if(root == NULL)
        return 0;
    return (1 + max(height(root->Lefl_node), height(root->Right_node)));
}
int max(int a, int b){
    return(a >= b)? a : b;
}
int balancedTree(Node* root){
    int lh;
    int rh;

    if(root == NULL)
        return 1;
    lh = height(root->Lefl_node);
    rh = height(root->Right_node);

    if((abs(lh - rh) <= 1) && balancedTree(root->Lefl_node) && balancedTree(root->Right_node))
        return 1;
    return 0;
}


//2.------------------------------------------------------------------
Node* buildTree(int size){
    Node* newNode;
    int x;
    int nL;
    int nR;

    if(size == 0){
        return NULL;
    }else{
        x = rand()%100000;
        nL = size / 2;
        nR = size - nL - 1;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->Lefl_node  = buildTree(nL);
        newNode->Right_node = buildTree(nR);
    }
    return newNode;
}

void printTree(Node* root){
    if(root){
        printf("%d",root->data);
        if(root->Lefl_node || root->Right_node){
            printf("(");
            if(root->Lefl_node)
                printTree(root->Lefl_node);
            else
                printf("NULL");
            printf(",");
            if(root->Right_node)
                printTree(root->Right_node);
            else
                printf("NULL");
            printf(")");
        }
    }
}

//4.------------------------------------------------------------------
int binSearch(Node* root, int value){
    if(root == NULL)
        return 0;
    if(root->data == value)
        return 1;
    Node* current = root;
    while(current->data != value){
        if(value < current->data)
            current = current->Lefl_node;
        else
            current = current->Right_node;
        if(current == NULL)
            return 0;
    }
}

int binSearchReq(Node* root, int value){
    if(root == NULL)
        return 0;
    if(root->data == value)
        return 1;
    if(binSearchReq(root->Right_node, value))
        return 1;
    if(binSearchReq(root->Lefl_node, value))
        return 1;
    return 0;
}

Node* buildImbalancedTree(int size){
    Node* newNode;
    int x;
    int nL;
    int nR;

    if(size == 0){
        return NULL;
    }else{
        x = rand()%100000;
        nL = 1;
        nR = size - 1;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->Lefl_node  = buildTree(nL);
        newNode->Right_node = buildTree(nR);
    }
    return newNode;
}


void makeSearchTree(Node* root){
    root->data = 15;

    root->Lefl_node->data = 8;
    root->Lefl_node->Lefl_node->data = 4;
    root->Lefl_node->Right_node->data = 5;

    root->Right_node->data = 30;
    root->Right_node->Lefl_node->data = 20;
    root->Right_node->Right_node->data = 50;
}

int main(){
    printf("\n\n");

//1.------------------------------------------------------------------
//2.------------------------------------------------------------------
    int percent_counter = 0;
    Node* tree[50];
    for(int i = 0; i < 50; i++){
        tree[i] = buildTree(10000);
        if(balancedTree(tree[i]))
            percent_counter++;
    }
    printf("Percent of balanced trees is: %f%", ((percent_counter/50.0)*100));
    printf("\n\n");

//3.------------------------------------------------------------------
    printf("Not balanced Tree: ");
    Node* notbalansedtree;
    notbalansedtree = buildImbalancedTree(6);
    printTree(notbalansedtree);

    if(balancedTree(notbalansedtree))
        printf("other tree is balansed\n");
    else
        printf("other tree is not balansed\n");
//4.------------------------------------------------------------------
    printf("\n\n");

    Node* searchTree;
    searchTree = buildTree(7);
    makeSearchTree(searchTree);
    printTree(searchTree);
    printf("\n");

    if(binSearchReq(searchTree, 30))
        printf("Number 30 exists in the Tree");
    else
        printf("Number 30 doesn't exist in the Tree");
    printf("\n");
    if(binSearchReq(searchTree, 33))
        printf("Number 33 exists in the Tree");
    else
        printf("Number 33 doesn't exist in the Tree");
    printf("\n");

    return 0;
}
