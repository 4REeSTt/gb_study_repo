#include <iostream>
#include "./variables.h"

float calculate(int a,int b,int c,int d){
    return (a*(b + ((float)c/d)));

}

int main(){
//2
    int task2_number = 30;
//1.//Закоментировано для задания 3, эти же переменные с другими значениями идут из файла
    //int a,b,c,d;
    //a = 5; b = 14;
    //c = 9; d = 23;

    std::cout << "Task1/3: \n" << calculate(a,b,c,d) << "\n\n";

    std::cout << "Task2:   \n" << ((task2_number > 21)? 2*(task2_number - 21):task2_number - 21) << "\n\n";

//4.
    int Array_3D[3][3][3] = {0};
    Array_3D[1][1][1] = 31;
    int * index = &Array_3D[1][1][1];
    std::cout << "Task4:\n" <<*index << "\n\n";
    return 0;
}
