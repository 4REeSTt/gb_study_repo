#include <iostream>

//1.-----------------------------------------------------
template<class T>
T div(T& value1 , T& value2){
    if((int)value2 == 0)
        throw 0;
    return value1/value2;
}
//2.-----------------------------------------------------
class Ex{
public:
    Ex(double x)
    :x(x)
    {}
    double GetX(){return x;}
private:
    double x;
};

class Bar{
public:
    void set(double a){
        if(a + y > 100){
            throw Ex(a*y);
        }else{
            y = a;
        }
    }
private:
    double y = 0;
};
//3.-----------------------------------------------------
class IlligalCommand{
public:
private:
};
class OffTheField{
public:
prtivate:
};
class Robot{
public:
    void move(){}
private:
    uint8_t m_x;
    uint8_t m_y;
    int8_t m_direction;

};

int main(){
//1.-----------------------------------------------------
    int a{15};
    int b{0};

    try{
        std::cout << div<int>(a,b) << "\n";
    }
    catch(...){
        std::cout << "Devision by 0\n";
    }
//2.-----------------------------------------------------
    double n = -1;
    Bar bar;
    while(n){
        std::cin >> n;
        try{
            bar.set(n);
        }
        catch(Ex ex){
            std::cout << "Expression x = "<< ex.GetX() << std::endl; 
        }
    }
//3.-----------------------------------------------------
    return 0;
}
