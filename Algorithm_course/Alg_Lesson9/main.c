#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 50
#define STACK_EMPTY (-1)

typedef struct Queue{
    int data;
    struct Queue* next;
}Queue;


Queue* queue;


void init(){
    queue = (Queue*)malloc(sizeof(Queue));
    queue->data = 0;
    queue->next = NULL;
}
void add_queue(int value){
    Queue* tmp = queue;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = (Queue*)malloc(sizeof(Queue));
    tmp->next->data = value;
    tmp->next->next = NULL;
}
int pop_queue(){
    if(queue->next == NULL){
        printf("queue is empty\n");
        return -1;
    }
    int value = queue->next->data;
    Queue* link = queue->next->next;
    free(queue->next);
    queue->next = link;
    return value;
}
void bubble_sort(int * Arr,int length){
    int tmp ;
    while(length > 1){
        for(int i = 0;i < length;i++){
            if(Arr[i] > Arr[i + 1]){
                tmp = Arr[i];
                Arr[i] = Arr[i + 1];
                Arr[i + 1] = tmp;
            } 
        }
        length--;
    }
}



typedef struct Node{
    int data;
    int prior;
}Node;

int counter = -1;

int Stack[STACK_SIZE];
int top = -1;

//stack logic
int push(int value){
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

const int size = 6;
int matrix[6][6] = {
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0},
};
int other_matrix[6][6] = {
    {0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
};

int visited[6] = {0};
void clear_visited(){
    for(int i = 0; i < 6; i++)
        visited[i] = 0;
}



//1.-----------------------------------------------------------
int depthThrough_using_STACK(int start){
    visited[start] = 1;
    push(start);
    while(1){
        printf("%d ", start);
        for(int i = 0; i < size; i++){
            if((matrix[start][i] == 1) && !visited[i]){
                push(i);
            }
        }
        start = pop();
    }
}
//2,3-----------------------------------------------------------
void count_half_entering(){
    int counter = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(matrix[i][j])
                counter++;
        }
        printf("For knot %d there is %d connections\n", i, counter);
        counter = 0;
    }
}

int depthThrough(int start){
    int current_number;
    visited[start] = 1;
    printf("%d ", start);
    for(int current_number = 0; current_number < size; current_number++){
        if((matrix[start][current_number] == 1) && !visited[current_number])
            depthThrough(current_number);
    }
}


int widthThrough(int start){
    int x;
    add_queue(start);
    while((x = pop_queue()) != -1){
        if(visited[x] == 1) continue;
        visited[x] = 1;
        printf("%d ", x);
        for(int i = 0; i < size; i++)
            if((matrix[x][i]) == 1 && visited[i] == 0)
                add_queue(i);
    }
}

//4.-----------------------------------------------------------
int make_it_zerro(int* arr){
    for(int i = 0; i < size; i++)
        arr[i] = 0;
}
int GoThroughMatrix(){
    int connections_counting[size];
    int sorted_knots[size];
    make_it_zerro(connections_counting);
    make_it_zerro(sorted_knots);

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(other_matrix[i][j]){
                connections_counting[i]++;
                sorted_knots[i]++;
            }
    bubble_sort(sorted_knots, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(sorted_knots[i] == connections_counting[j]){
                printf("%d ", j);
                connections_counting[j] = -1;
                break;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < size; i++)
        printf("%d ", sorted_knots[i]);
    printf("\n");
}

int main(){
    init();
    printf("\n");

//1.-----------------------------------------------------------
    printf("Deep going through graph with STACK: ");
    depthThrough(3);
    clear_visited();
    printf("\n");


//2,3-----------------------------------------------------------
    count_half_entering();

    printf("Deep going through graph: ");
    depthThrough(3);
    clear_visited();
    printf("\n");


    printf("Width going through graph: ");
    widthThrough(3);
    clear_visited();
    printf("\n");
   
//4.-----------------------------------------------------------
    printf("Go through matrix and print all knots by connections: \n");
    GoThroughMatrix();


    return 0;
}
