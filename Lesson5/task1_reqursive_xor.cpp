#include <iostream>
namespace Task5{
    //1.---//5.
    int rqur(int * Array, int length){
         if(length > -1){
             Array[length] ^= 1;
             rqur(Array, length - 1);
         }else{ return 0;}
         return 0;
    }
}

void rqur_new(){}

template<typename counter,typename... LIST>

void rqur_new(counter first_item,LIST... args){
    std::cout << (first_item ^= 1) << " ";
    
    rqur_new(args...);
}

