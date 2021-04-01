#include <iostream>


//1.----------------------------------------------------
bool does_sum_numbers_belongs_10_20(int a, int b){
    if((a + b) >= 10 and (a + b) <= 20){
        return true;
    }else{
        return false;
    }
}

//2.----------------------------------------------------
bool is_num_simple(unsigned int num){
    for(int i = 2; i < num; i++){
        if(num % i ==0){
            return false;
        }
    }
    return true;
}

//3.----------------------------------------------------
bool nums_is_10_or_sum_is_10(){
   const int a = 9, b = 10;
   if(((a == b)and a == 10) or (a + b) == 10){
        return true;
   }return false;
}


//4.----------------------------------------------------
bool year_is_leap(int year){
    while(year % 100 == 0){
        year /= 100;
    }
    if(year % 4 == 0){
        return true;
    }
    return false;
}


//=====================================================
int main(){
//Для проверки функций:
    std::cout << "Task1:\n" << does_sum_numbers_belongs_10_20(10,10) << "\n\n";
    std::cout << "Task2:\n" << is_num_simple(7) << "\n\n";
    std::cout << "Task3:\n" << nums_is_10_or_sum_is_10() << "\n\n"; //целочисленные костанты указаны в начале функции.


    std::cout << "Task4:\n"<< year_is_leap(2000) << "\n\n";
    return 0;
}
