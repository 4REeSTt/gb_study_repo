#include <iostream>


//max usage is !65 = 9223372036854775808
uint64_t find_factorial(uint64_t number_to_find){
    uint64_t factorialIs;
    if (number_to_find == 0){
        return 1;
    }else{
        factorialIs = number_to_find * find_factorial(number_to_find - 1);
        return factorialIs;
    }
}

int main(){
    int fuc_num;
    std::cout << "Enter factorial to find" << std::endl;
    std::cin >> fuc_num;
    std::cout << find_factorial(fuc_num) << std::endl;
    return 0;
}
