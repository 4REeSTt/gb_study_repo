#include <iostream>
#include <string.h>
#include <typeinfo>

//5//-------------------------------------------------
union diferent_types{
    int   integer;
    float float_point;
    char  symbol;
};

struct type_ident{
    diferent_types value;
    int is_int  :1;
    int is_char :1;
    int is_float:1;

};


//2//-------------------------------------------------
enum Square_statement{ 
    Empty,
    Cross, 
    Zerro,
};


//4//-------------------------------------------------
    struct Game_field{
        Square_statement square[3][3];
   std::string Player1_name;
   std::string Player2_name;
        int Cycle  :10;
        int turn :2;
    }; 
//----------------------------------------------------


int main(){
//1//-------------------------------------------------
    bool boolea = true;
    int integer = 10;
    double float_number = 15.5;
    char letter = 's';
    std::string str = "Hello World";

//3//-------------------------------------------------
    Square_statement Field[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            Field[i][j] = Empty;
            std::cout << Field[i][j] << " ";
        }
    }
//5.--------------------------------------------------
    type_ident inte;
    inte.value.integer = 15;
    inte.is_int = 1;
    inte.is_char = 0;
    inte.is_float = 0;

    std::cout << "\n" << inte.value.integer;

    return 0;
}
