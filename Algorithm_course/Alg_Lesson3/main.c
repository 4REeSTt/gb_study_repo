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
int ChessBoard[8][8] = {0};
int RoadCounter[64] = {0};

struct Piece{
        struct Piece(int pos_x, int pos_y){
            x = pos_x; y = pos_y; 
        }
        void moveUP(bool side){
            if(!side)
                y--;
            else
                y++;
        }
        void moveRight(bool side){
            if(!side)
                x++;
            else
                x--;
        }
        void moveUpRight(bool side){
            if(!side){
                x++;y--;
            }else{
                x--;y++;
            }
        }
        void moveUpLeft(bool side){
            if(!side){
                y--;x--;
            }else{
                y++;x++;
            }
        }

    private:
        int x,y;
};

int KingsRoads(int* board, int* roads){
   return 0; 
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
    struct Piece King(0, 0); 




    return 0;
}
