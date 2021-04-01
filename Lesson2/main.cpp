#include <iostream>
#include <string.h>

//5//-------------------------------------------------
    union diferent_types_number{
        int   integer;
        float float_point;
        char  symbol;
    };
    struct num_type_identifyer{
        bool  i:1;
        bool  f:1;
        bool ch:1;
    };

//2//-------------------------------------------------
enum Square_statement{ 
    Empty,
    Cross, 
    Zerro,
};


int find_type_num(number){
    if(number.integer > 0){
        identify.i  = 1;
        identify.f  = 0;
        identify.ch = 0;
    }else if(number.float_point > 0)   
    

    return 0;
}


int main(){
//1//-------------------------------------------------
    bool boolea = true;
    int integer = 10;
    double float_number = 15.5;
    char letter = 's';
    std::string str = "Hello World";

//3//-------------------------------------------------
    Square_statement Field[3][3];

//4//-------------------------------------------------
    struct Game_field{
        std::string Player1_Name;
        std::string Player2_Name;
        int  Cycle: 9;
        bool turn;
    }; 
//----------------------------------------------------

    diferent_types_number number;
    num_type_identifyer identify;
    
    number.integer = 15;
// call what type is number?

    
    




return 0;
}
