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
const int size = 8;
int ChessBoard[64] = {0};
int RoadCounter[64] = {0};

void KingRoads(int* board, int* counter, int size){
    for(int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if(board[j + i*size]){
                break;
            }
            if(!i){
                if(!j){
                    counter[j] = 1;

                    continue;
                }else{
                    counter[j] = counter[j -1];
                    continue;
                }
            }else{
                if(!j){
                    counter[j + i*size] = counter[j + (i-1)*size];
                    continue;
                }else{
                    counter[j + i*size] = counter[j + (i-1)*size] + counter[j + i*size -1];
                    continue;
                }
            }
        }
    }
}

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
    ChessBoard[1] = 1;
    ChessBoard[6] = 1;
    ChessBoard[10] = 1;
    ChessBoard[37] = 1;

    KingRoads(ChessBoard, RoadCounter, size);
    printf("\nNomber of possible ways is:%d\n\n", RoadCounter[size*size-1]);
    for(int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            printf("%d\t", RoadCounter[j + i*size]);
        }
        printf("\n");
    }

    



    return 0;
}
