#include <iostream>






    
struct game_struct{
    char name[15];
};




int main(){
//1.
    int integer = 10;
    double float_number = 15.5;
    char letter = 's';
    //std::cout << letter << "\t" << float_number << "\t" << integer << std::endl; 
    

    //Инициализируем перепенные которые будут записываться в массив
    //И сам массив(для игры необходимо всего 9 значений)
    char cross = 'x', zerro = 'o';
    char game_arr[9];
    game_arr[0] = cross;
    game_arr[1] = zerro;
    game_arr_length = 2;

    for (int i = 0; i < game_arr_length; i++){
        std::cout << game_arr[i] << " ";
    }
    


return 0;
}
