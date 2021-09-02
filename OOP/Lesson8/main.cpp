#include <iostream>

template<class T>
T div(T& value1 , T& value2){
    if((int)value2 == 0)
        throw 0;
    return value1/value2;
}


int main(){
    int a{15};
    int b{0};

    try{
        std::cout << div<int>(a,b) << "\n";
    }
    catch(...){
        std::cout << "Devision by 0\n";
    }
    return 0;
}
